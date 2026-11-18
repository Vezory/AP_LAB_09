// Lab_09_2_1.cpp
// Лабораторна робота № 9.2 (Частина 1)
// Тема: Директиви препроцесора та макровизначення
// Варіант: 16
// Студент: Новосад Захарій Володимирович, група РІ-13

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// =============================================================================
// КОНСТАНТА ДЛЯ ДИРЕКТИВ УМОВНОЇ КОМПІЛЯЦІЇ
// За умовою варіанта 16:
//   Гілка 1: якщо Z > 1  --> w = min((x - z)^2, x - y)
//   Гілка 2: якщо Z <= 1 --> w = max(x - y, y - z)
// Зараз Z = 1, тому компілюється Гілка 2!
// =============================================================================
#define Z 1

// =============================================================================
// МАКРОВИЗНАЧЕННЯ (МАКРОСИ З ПАРАМЕТРАМИ)
// Всі аргументи обов'язково беруться в дужки, щоб зберегти пріоритет операцій
// =============================================================================
#define SQR(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ABS(x) (((x) < 0) ? (-(x)) : (x))

// Макроси виведення результатів
#define PRINTI(w) puts("control output"); printf(#w" = %d\n", (int)(w))
#define PRINTR(w) puts("rezult :"); printf(#w" = %f\n", (float)(w))

// Допоміжні функції для Unit-тестів
double calc_branch1(double x, double y, double z) {
    return MIN(SQR(x - z), x - y);
}

double calc_branch2(double x, double y, double z) {
    return MAX(x - y, y - z);
}

#ifndef UNIT_TEST
int main()
{
    puts("===================================================================");
    puts("  Lab 9.2.1: Preprocessor Directives and Macros (Variant 16)");
    puts("  Student: Novosad Zakharii, Group: RI-13");
    puts("===================================================================");

    double x, y, z;
    double w;
    char ch;

    do {
#if Z > 1
        puts("\n[PREPROCESSOR]: Active Branch 1 (Z > 1)");
        puts("Formula: w = min((x - z)^2, x - y)");

        printf("Input x: ");
        if (scanf("%lf", &x) != 1) break;

        printf("Input y: ");
        if (scanf("%lf", &y) != 1) break;

        z = Z;
        printf("Constant Z = %f\n", z);

        w = MIN(SQR(x - z), x - y);
        PRINTR(w);
#else
        puts("\n[PREPROCESSOR]: Active Branch 2 (Z <= 1)");
        puts("Formula: w = max(x - y, y - z)");

        printf("Input x: ");
        if (scanf("%lf", &x) != 1) break;

        printf("Input y: ");
        if (scanf("%lf", &y) != 1) break;

        z = Z;
        printf("Constant Z = %f\n", z);

        w = MAX(x - y, y - z);
        PRINTR(w);
#endif

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
        puts("");
    } while (ch == 'y' || ch == 'Y');

    puts("Calculations finished. Exiting program.");
    return 0;
}
#endif
