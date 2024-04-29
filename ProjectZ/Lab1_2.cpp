#define PR(x) printf("x=%p, *x=%f, &x=%p\n", (void*)x, *x, (void*)&x)
#include <stdio.h>

int main(void)
{
    double mas[] = { 1.0, 2.0, 3.0 };
    double* ptr1, * ptr2;
    ptr1 = mas;
    ptr2 = &mas[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2 - ptr1 = %td\n", ptr2 - ptr1);
    return 0;
}