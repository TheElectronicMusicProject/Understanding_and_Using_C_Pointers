#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    int matrix[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
    int (*pmatrix)[5] = matrix;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            printf("matrix[%d][%d]  Address: %p Value: %d\n",
                   i, j, &matrix[i][j], matrix[i][j]);
            printf("%p\n", matrix[0] + i * 5 + j);
        }
    }

    printf("%p\n", pmatrix);
    printf("%p\n", matrix);
    printf("%p\n", pmatrix[0] + 1);
    printf("%p\n", matrix[0] + 1);
    printf("%p\n", pmatrix + 1);
    printf("%p\n", matrix + 1);
    printf("%d\n", sizeof(pmatrix[0]));
    printf("%d\n", sizeof(matrix[0]));

	return (0);
}	/* main() */