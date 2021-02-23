// gcc sort_array_methods.c --std=c1x

#include <stdio.h>
#include <stdlib.h> // malloc

double* generate_vector(const int n)
{
    double *v = (double*)malloc( sizeof(double) * n );
    for (double *p = v; p < v + n; p++)
        *p = (double)rand() / rand();
    return v;
}

void print_vector(double *v, const int n)
{
    for (double *p = v; p < v + n; p++)
        printf("%6.2lf ", *p);
    printf("\n");
}

void swap(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(double *v, int n)
{
    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j+1])
                swap(&v[j], &v[j+1]);
}

int main(void)
{
    int n = 10;
    double *v = generate_vector(n);
    print_vector(v, n);
    bubble_sort(v, n);
    print_vector(v, n);

    return 0;
}