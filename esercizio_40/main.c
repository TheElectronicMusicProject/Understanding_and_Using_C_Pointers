#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    int (*(arr1[])) = {(int[]) {0, 1, 2},
                       (int[]) {3, 4, 5},
                       (int[]) {6, 7, 8}};

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 3; ++i)
        {
            printf("arr1[%d][%d]    Address: %p Value: %d\n",
                   j, i, &arr1[j][i], arr1[j][i]);
        }

        printf("\n");
    }

    int (*(arr2[])) = {(int[]) {0, 1, 2, 3},
                       (int[]) {4, 5},
                       (int[]) {6, 7, 8}};
    int row = 0;

    for (int i = 0; i < 4; ++i)
    {
        printf("arr2[%d][%d]    Address: %p Value: %d\n",
               row, i, &arr2[row][i], arr2[row][i]);
    }
    printf("\n");

    row = 1;
    for (int i = 0; i < 2; ++i)
    {
        printf("arr2[%d][%d]    Address: %p Value: %d\n",
               row, i, &arr2[row][i], arr2[row][i]);
    }
    printf("\n");

    row = 2;
    for (int i = 0; i < 3; ++i)
    {
        printf("arr2[%d][%d]    Address: %p Value: %d\n",
               row, i, &arr2[row][i], arr2[row][i]);
    }
    printf("\n");

	return (0);
}	/* main() */