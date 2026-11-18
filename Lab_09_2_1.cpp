#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Визначення константи z для умовної компіляції (препроцесор)
#define Z 2

// Макроси обчислень за варіантом 16
#define SQR(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(x) (((x) < 0) ? (-(x)) : (x))

// Макроси виведення результатів
#define PRINTI(w) puts("control output"); printf(#w" = %d\n", (int)(w))
#define PRINTR(w) puts("rezult :"); printf(#w" = %f\n", (float)(w))

// Функції-обгортки для Unit-тестів
double calc_branch1(double x, double y, double z) {
    return MIN(SQR(x - z), x - y);
}

double calc_branch2(double x, double y, double z) {
    return MAX(x - y, y - z);
}

#ifndef UNIT_TEST
int main()
{
    puts("Lab 9.2.1. Using macros and preprocessing directives (Variant 16)");
    double x, y, z;
    double w;
    char ch;

    do {
#if Z > 1
        puts("Branch 1: z > 1, formula: w = min((x - z)^2, x - y)");
        printf("Input x: ");
        if (scanf("%lf", &x) != 1) break;
        printf("Input y: ");
        if (scanf("%lf", &y) != 1) break;
        
        // Значення z фіксоване для умовної компіляції
        z = Z;
        printf("Constant Z = %f\n", z);

        w = MIN(SQR(x - z), x - y);
        PRINTR(w);
#else
        puts("Branch 2: z <= 1, formula: w = max(x - y, y - z)");
        printf("Input x: ");
        if (scanf("%lf", &x) != 1) break;
        printf("Input y: ");
        if (scanf("%lf", &y) != 1) break;

        z = Z;
        printf("Constant Z = %f\n", z);

        w = MAX(x - y, y - z);
        PRINTR(w);
#endif

        printf("\nContinue? (y/n): ");
        scanf(" %c", &ch);
        puts("");
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
#endif
