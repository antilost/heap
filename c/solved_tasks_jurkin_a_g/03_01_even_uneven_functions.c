/*
 * Численная проверка чётности/нечётности для заданной функции на интервале [a; b] с шагом dx.
 * antilost@antilost:~/heap/c/solved_tasks_jurkin_a_g$ gcc 03_01_even_uneven_functions.c -lm && ./a.out
 * EVEN
 *
 * Для линковки модуля math.h нужно указать ключ -lm
 * 
 */

#include <stdio.h>
#include <math.h>

const double EPS = 1e-2;

double my_func(double x)
{
    return fabs(x);
}

main()
{
    double a, b, dx;
    a = -5; b = 5; dx = 0.1;

    double (*funcs[3])(double);
    funcs[0] = cos;
    funcs[1] = sin;
    funcs[2] = my_func;

    int i;
    for (i = 0; i < 3; i++)
    {
        double xl, xr;

        int is_even = 1;
        double (*func)(double);
        func = funcs[i];
        for (xl = a, xr = b; xl < xr; xl += dx, xr -= dx)
        {
            double fxl, fxr, diff;
            fxl = func(xl); //pow(xl, 3);
            fxr = func(xr); //pow(xr, 3);
            diff = fabs(fxl - fxr);
    
            //printf("%6.4f %6.4f %6.4f %6.4f %6.4f\n", xl, xr, fxl, fxr, diff);
            if (diff > EPS)
            {
                is_even = 0;
                break;
            }
        }
        printf(is_even ? "EVEN\n" : "UNEVEN\n");
    }
}
