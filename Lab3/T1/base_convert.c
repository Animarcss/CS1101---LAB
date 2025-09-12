/* base_convert.c
 * Usage:
 *   ./base_convert -b <int>     # 32-bit binary (two's complement)
 *   ./base_convert -o <int>     # 32-bit octal, 11 digits
 *   ./base_convert -x <int>     # 32-bit hex, 8 digits (uppercase)
 *   ./base_convert -f <float>   # show float value + its 32-bit memory content
 *   ./base_convert -d <double>  # show double value + its 64-bit memory content
 *
 * Integer input accepts 123 (dec), 077 (oct), 0x7B (hex); negatives OK (two's complement).
 * Float/Double input accepts standard C forms: 1.5, -0.0, 1e-3, inf, nan, etc.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>

static void usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s <-b|-o|-x> <integer>\n"
        "       %s -f <float>\n"
        "       %s -d <double>\n"
        "  -b : 32-bit binary (two's complement)\n"
        "  -o : 32-bit octal (11 digits)\n"
        "  -x : 32-bit hexadecimal (8 digits)\n"
        "  -f : show float value and its 32-bit memory content (IEEE-754)\n"
        "  -d : show double value and its 64-bit memory content (IEEE-754)\n",
        prog, prog, prog);
}

static void print_binary32(uint32_t u) {
    putchar('0'); putchar('b');
    for (int i = 31; i >= 0; --i) {
        putchar(((u >> i) & 1U) ? '1' : '0');
    }
    putchar('\n');
}

static void print_binary64(uint64_t u) {
    putchar('0'); putchar('b');
    for (int i = 63; i >= 0; --i) {
        putchar(((u >> i) & 1ULL) ? '1' : '0');
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    if (argc != 3) { usage(argv[0]); return 1; }

    const char *mode = argv[1];
    const char *numstr = argv[2];

    if (strcmp(mode, "-f") == 0 || strcmp(mode, "--float") == 0) {
        /* Parse float */
        errno = 0;
        char *end = NULL;
        float fv = strtof(numstr, &end);
        if (end == numstr || *end != '\0') {
            fprintf(stderr, "Error: invalid float: '%s'\n", numstr);
            return 2;
        }
        if (errno == ERANGE) {
            fprintf(stderr, "Warning: float out of range (parsed as %g)\n", fv);
        }

        /* Extract raw 32-bit pattern (IEEE-754 single) */
        uint32_t bits = 0;
        memcpy(&bits, &fv, sizeof(bits));

        /* Also show the 4 bytes as stored in memory (host endianness) */
        unsigned char bytes[4];
        memcpy(bytes, &fv, 4);

        /* Break into fields */
        uint32_t sign = bits >> 31;
        uint32_t exp  = (bits >> 23) & 0xFFu;
        uint32_t frac =  bits        & 0x7FFFFFu;

        /* Classify */
        const char *cls = NULL;
        if (exp == 0xFFu) {
            cls = (frac == 0) ? (sign ? "-infinity" : "+infinity") : "NaN";
        } else if (exp == 0u) {
            cls = (frac == 0) ? (sign ? "-0 (zero)" : "+0 (zero)") : "subnormal";
        } else {
            cls = "normalized";
        }

        /* Print everything */
        printf("Float input      : %s\n", numstr);
        printf("Parsed value     : %.9g\n", fv);                  /* ~float precision */
        printf("Bits (hex)       : 0x%08" PRIX32 "\n", bits);
        printf("Bits (binary)    : ");
        print_binary32(bits);
        printf("Bytes in memory  : %02X %02X %02X %02X  (low addr -> high addr)\n",
               bytes[0], bytes[1], bytes[2], bytes[3]);
        printf("IEEE-754 fields  : sign=%u, exponent=0x%02X (%u), fraction=0x%06X\n",
               sign, exp, exp, frac);
        printf("Classification   : %s\n", cls);
        return 0;
    }

    if (strcmp(mode, "-d") == 0 || strcmp(mode, "--double") == 0) {
        /* Parse double */
        errno = 0;
        char *end = NULL;
        double dv = strtod(numstr, &end);
        if (end == numstr || *end != '\0') {
            fprintf(stderr, "Error: invalid double: '%s'\n", numstr);
            return 2;
        }
        if (errno == ERANGE) {
            fprintf(stderr, "Warning: double out of range (parsed as %g)\n", dv);
        }

        /* Extract raw 64-bit pattern (IEEE-754 double) */
        uint64_t bits = 0;
        memcpy(&bits, &dv, sizeof(bits));

        /* Also show the 8 bytes as stored in memory (host endianness) */
        unsigned char bytes[8];
        memcpy(bytes, &dv, 8);

        /* Break into fields */
        uint64_t sign = bits >> 63;
        uint64_t exp  = (bits >> 52) & 0x7FFULL;
        uint64_t frac =  bits        & 0xFFFFFFFFFFFFFULL;

        /* Classify */
        const char *cls = NULL;
        if (exp == 0x7FFULL) {
            cls = (frac == 0) ? (sign ? "-infinity" : "+infinity") : "NaN";
        } else if (exp == 0ULL) {
            cls = (frac == 0) ? (sign ? "-0 (zero)" : "+0 (zero)") : "subnormal";
        } else {
            cls = "normalized";
        }

        /* Print everything */
        printf("Double input     : %s\n", numstr);
        printf("Parsed value     : %.17g\n", dv);                 /* ~double precision */
        printf("Bits (hex)       : 0x%016" PRIX64 "\n", bits);
        printf("Bits (binary)    : ");
        print_binary64(bits);
        printf("Bytes in memory  : %02X %02X %02X %02X %02X %02X %02X %02X  (low addr -> high addr)\n",
               bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5], bytes[6], bytes[7]);
        printf("IEEE-754 fields  : sign=%" PRIu64 ", exponent=0x%03" PRIX64 " (%" PRIu64 "), fraction=0x%013" PRIX64 "\n",
               sign, exp, exp, frac);
        printf("Classification   : %s\n", cls);
        return 0;
    }

    /* Integer modes: -b/-o/-x */
    errno = 0;
    char *end = NULL;
    long long sval = strtoll(numstr, &end, 0); /* base 0: 0x.. and 0.. handled */
    if (errno == ERANGE) {
        fprintf(stderr, "Error: value out of range.\n");
        return 2;
    }
    if (end == numstr || *end != '\0') {
        fprintf(stderr, "Error: invalid integer: '%s'\n", numstr);
        return 2;
    }

    /* Convert to 32-bit two's complement bit pattern */
    uint32_t u32 = (uint32_t)sval;

    if (strcmp(mode, "-b") == 0 || strcmp(mode, "--bin") == 0) {
        print_binary32(u32);
    } else if (strcmp(mode, "-o") == 0 || strcmp(mode, "--oct") == 0) {
        /* 32 bits -> 11 octal digits; pad with leading zeros */
        printf("0%011" PRIo32 "\n", u32);
    } else if (strcmp(mode, "-x") == 0 || strcmp(mode, "--hex") == 0) {
        /* 32 bits -> 8 hex digits; pad with leading zeros */
        printf("0x%08" PRIX32 "\n", u32);
    } else {
        usage(argv[0]);
        return 1;
    }

    return 0;
}
