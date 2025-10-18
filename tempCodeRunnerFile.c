#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *info;
    char buffer[80];

    // Get current time
    time(&rawtime);

    // Convert to local time
    info = localtime(&rawtime);

    // Format and print the time
    strftime(buffer, 80, "Current local time: %A, %B %d, %Y %H:%M:%S", info);
    printf("%s\n", buffer);

    return 0;
}