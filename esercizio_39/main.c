#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    /* NON GARANTITA LA CONTIGUITA' */
    printf("Caso #1\n");
    int rows = 2;
    int cols = 5;

    int ** matrix = (int **) malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%p\n", &matrix[i][j]);
        }
    }
    
    /* ALLOCAZIONE CONTIGUA 1 */
    printf("Caso #2\n");
    int rows1 = 2;
    int cols1 = 5;

    int ** matrix1 = (int **) malloc(rows1 * sizeof(int *));
    matrix1[0] = (int *) malloc(rows1 + cols1 * sizeof(int));

    for (int i = 0; i < rows1; ++i)
    {
        matrix1[i] = matrix1[0] + i * cols1;
    }

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j)
        {
            printf("%p\n", &matrix1[i][j]);
        }
    }

    /* ALLOCAZIONE CONTIGUA 2 */
    printf("Caso #3\n");
    int rows2 = 2;
    int cols2 = 5;

    int * matrix2 = (int *) malloc(cols2 * rows2 * sizeof(int));

    for (int i = 0; i < rows2; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            printf("%p\n", (matrix2 + (i * cols2) + j));
        }
    }

    /* ALLOCAZIONE CONTIGUA 3 */
    printf("Caso #4\n");
    int rows3 = 2;
    int cols3 = 5;

    int (*matrix3)[cols3] = (int (*)[cols3]) malloc(rows3 * cols3 * sizeof(int));

    for (int i = 0; i < rows3; ++i)
    {
        for (int j = 0; j < cols3; ++j)
        {
            printf("%p\n", &matrix3[i][j]);
        }
    }

	return (0);
}	/* main() */