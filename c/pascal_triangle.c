#include <stdio.h>
#include <malloc.h>

#define ROWS_MAX 20

main()
{
    int rows;
    int** M;
    int i, j;

    do
    {
        printf("rows: ");
        scanf("%d", &rows);
    }
    while (rows > ROWS_MAX || rows < 0);

    M = (int**)malloc( rows * sizeof(int*) );
    for (i = 0; i < rows; i++)
    {
        int cols = i + 1;
        M[i] = malloc( cols * sizeof(int*) );
        M[i][0] = 1;
        M[i][cols - 1] = 1;
        if (i > 1) {
            for (j = 1; j < cols - 1; j++)
                M[i][j] = M[i-1][j -1] + M[i-1][j];
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < i + 1; j++)
            printf("%3d ", M[i][j]);
        puts("");
    }
}
