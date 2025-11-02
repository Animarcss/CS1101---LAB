#include <stdio.h>

//====================================================
// 1) basic struct declaration + dot assignment
//====================================================
#if 0
struct point {
    float xcoord;
    float ycoord;
};

int main(void) {
    struct point a = {3.2f, 1.5f};
    printf("%f %f\n", a.xcoord, a.ycoord);
}
#endif

//====================================================
// 2) typedef struct
//====================================================
#if 0
typedef struct {
    float real, imag;
} complex;

int main(void){
    complex a = {3,4};
    complex b = {7,8};
    printf("a=(%f,%f)\n",a.real,a.imag);
    printf("b=(%f,%f)\n",b.real,b.imag);
}
#endif

//====================================================
// 3) direct structure copy
//====================================================
#if 0
struct stud {
    int roll;
    char name[20];
    float marks;
};

int main(void){
    struct stud a = {23, "Kanika", 92.3};
    struct stud b;
    b = a;
    printf("%s %d %f\n",b.name,b.roll,b.marks);
}
#endif

//====================================================
// 4) array of structures
//====================================================
#if 0
struct rec {
    char name[50];
    float cpi;
};

int main(void) {
    struct rec s[3] = {
        {"aaa", 7.0},
        {"bbb", 9.1},
        {"ccc", 8.0}
    };

    for(int i=0;i<3;i++)
        printf("%s %.2f\n",s[i].name, s[i].cpi);
}
#endif

//====================================================
// 5) structure pointer + arrow operator
//====================================================
#if 0
typedef struct {
    int roll;
    char name[20];
    float cpi;
} student;

int main(void){
    student x = {24,"IITPatna",9.0};
    student *p = &x;
    printf("%d %s %f\n", p->roll, p->name, p->cpi);
}
#endif

//====================================================
// 6) nested struct
//====================================================
#if 0
typedef struct { float x,y; } point;

typedef struct {
    point a,b,c;
    float area;
} triangle;

int main(void){
    triangle T = {{0,0},{1,0},{0,1},0};
    T.area = (T.a.x*(T.b.y - T.c.y)
            + T.b.x*(T.c.y - T.a.y)
            + T.c.x*(T.a.y - T.b.y)) / 2.0f;
    if(T.area < 0) T.area = -T.area;
    printf("%f\n",T.area);
}
#endif

//====================================================
// 7) union inside struct
//====================================================
#if 0
typedef struct {
    char name[20];
    float cpi;
    char htype;
    union {
        char fps[8];
        int cgs;
        float mks;
    } height;
} stud;

int main(void){
    stud s = {"AAA", 9.5, 'm', .height.mks=1.80f};
    printf("%f\n",s.height.mks);
}
#endif
