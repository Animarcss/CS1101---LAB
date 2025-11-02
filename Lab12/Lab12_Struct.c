#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


// Pick which snippet to compile/run

#define RUN_EXAMPLE 1



// Common types used across examples
struct point { float xcoord, ycoord; };
typedef struct { float x, y; } point_t;


typedef struct { int roll; char name[32]; float marks; } stud_t;


typedef struct { float real, imag; } complex_t;


// ---------------- EXAMPLE 1 ----------------
#if RUN_EXAMPLE == 1
int main(void) {
struct point a, b, c; // definition+declaration demo
a.xcoord = 1.5f; a.ycoord = 2.5f;
b.xcoord = -3.0f; b.ycoord = 4.0f;
c = (struct point){0};
printf("a=(%.1f,%.1f) b=(%.1f,%.1f) c=(%.1f,%.1f)\n",
a.xcoord,a.ycoord,b.xcoord,b.ycoord,c.xcoord,c.ycoord);
return 0;
}
#endif


// ---------------- EXAMPLE 2 ----------------
#if RUN_EXAMPLE == 2
// typedef for named & anonymous struct
typedef struct point point_named; // alias for struct point
typedef struct { float xcoord, ycoord; } point_anon; // anonymous + typedef
int main(void) {
point_named p1 = {2.0f, 1.0f};
point_anon p2 = {3.0f, 4.0f};
printf("p1=(%.1f,%.1f) p2=(%.1f,%.1f)\n", p1.xcoord,p1.ycoord,p2.xcoord,p2.ycoord);
return 0;
}
#endif


// ---------------- EXAMPLE 3 ----------------
#if RUN_EXAMPLE == 3
int main(void) {
struct point a = {2.0f, 1.0f};
a.xcoord = 3.2f; // member access
printf("a.xcoord=%.1f a.ycoord=%.1f\n", a.xcoord, a.ycoord);
return 0;
}
#endif


// ---------------- EXAMPLE 4 ----------------
#if RUN_EXAMPLE == 4
int main(void) {
stud_t s1 = {23, "Kanika", 92.3f};
stud_t s2 = {47, "Sanjoy", 42.5f};
stud_t s3; s3 = s2; // struct assignment (deep copy of arrays inside)
printf("s3: roll=%d name=%s marks=%.1f\n", s3.roll, s3.name, s3.marks);
return 0;
}
#endif


// ---------------- EXAMPLE 5 ----------------
#if RUN_EXAMPLE == 5
#endif