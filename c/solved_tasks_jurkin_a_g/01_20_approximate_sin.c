// gcc 01_20_approximate_sin.c -lm && ./a.out
// Флаг -lm нужен, чтобы linker подключил библиотеку math.h

#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

double approximated_sin(double x) {
    double x_doubled = x * x;
    double x_tripled = x * x_doubled;
    return x - x_tripled / 6 + x_doubled * x_tripled / 120;
}

int main(void) {
    int i;
    double a, b, x, dx, y1, y2;
    a = 0;
    b = PI/2;
    dx = 0.05;
    x = a;
    do {
        y1 = sin(x);
        y2 = approximated_sin(x);
        printf("%2d x=%-20.4f sin(x)=%-10.4f approx: %-10.4f\n", i, x, y1, y2);
        x += dx;
        i++;
    } while (x <= b);
    
    getchar();

    return 0;
}
