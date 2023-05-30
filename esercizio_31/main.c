#include <stdio.h>

int
main (void)
{
    int idx;
    int vector[5] = {1, 2, 3, 4, 5};
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arr3d[3][2][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}},
                          {{9, 10, 11, 12}, {13, 14, 15, 16}},
                          {{17, 18, 19, 20}, {21, 22, 23, 24}}};

    for (idx = 0; idx < 5; ++idx)
    {
        printf("@%d, %p, %d\n", idx, vector + idx, vector[idx]);
    }
    printf("Number of elements is %d\n", sizeof(vector) / sizeof(int));

    for (idx = 0; idx < 2; ++idx)
    {
        printf("&matrix[%d]: %p, sizeof(matrix[%d]): %d\n",
               idx, &matrix[idx], idx, sizeof(matrix[idx]));
    }

    printf("sizeof(arr3d): %d\n", sizeof(arr3d));
    printf("sizeof(arr3d[%d]): %d\n", 0, sizeof(arr3d[0]));
    printf("sizeof(arr3d[%d][%d]): %d\n", 0, 0, sizeof(arr3d[0][0]));
    printf("sizeof(arr3d[%d][%d][%d]): %d\n", 0, 0, 0, sizeof(arr3d[0][0][0]));

	return (0);
}	/* main() */