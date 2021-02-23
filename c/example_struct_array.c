#include <stdio.h>

#define N_MAX 20

typedef struct {
    char name[1024];
    int math, physics;
} student;

input(student a[], int *len)
{
    int i;
    printf("Length: ");
    scanf("%d", len);

    for (i = 0; i < *len; i++)
    {
        printf("Student #%d:\n", i);
        printf("  name: ");
        scanf("%s", a[i].name);
        printf("  math: ");
        scanf("%d", &a[i].math);
        printf("  physics: ");
        scanf("%d", &a[i].physics);
    }
}

output(student a[], const int len)
{
    if (len == 0)
    {
        puts("Array is empty");
        return;
    }

    int i;
    printf("%2c. %10s %5s %7s\n", '#', "name", "math", "physics");
    for (i = 0; i < len; i++)
        printf("%2d. %10s %5d %7d\n", i, a[i].name, a[i].math, a[i].physics);
}

float find_math_average_grade(student a[], const int len)
{
    int i;
    float sum = 0;

    for (i = 0; i < len; i++)
        sum += (float)a[i].math;
    return sum / len;
}

main()
{
    student students[N_MAX];
    int n = 0;

    int c;
    do
    {
        puts("Choose action:");
        puts("1 - Input array of structures");
        puts("2 - Output array");
        puts("3 - Get average math grade");
        puts("0 - Exit");

        scanf("%d", &c);

        switch (c)
        {
            case 1:
                {
                    input(students, &n);
                    break;
                }
            case 2:
                {
                    output(students, n);
                    break;
                }
            case 3:
                {
                    if (n > 0)
                    {
                        float avg = find_math_average_grade(students, n);
                        printf("Average math grade is %.2f\n", avg);
                    }
                    break;
                }
        }

        puts("");
    }
    while (c != 0);
}
