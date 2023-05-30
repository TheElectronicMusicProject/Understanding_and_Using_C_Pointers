#include <stdio.h>
#include <stdlib.h>

int *
allocateArray (int size, int value)
{
    int * arr = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i)
    {
        arr[i] = value;
    }

    return arr;
}

int *
allocateArray_bad (int size, int value)
{
    int arr[size];

    for (int i = 0; i < size; ++i)
    {
        arr[i] = value;
    }

    return arr;
}

int *
allocateArray_good (int * arr, int size, int value)
{
    if (arr != NULL)
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] = value;
        }
    }

    return arr;
}

int
main (void)
{
    int * vector = allocateArray(5, 45);

    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", vector[i]);
    }

    free(vector);

    int vector_good[5];
    allocateArray_good(vector_good, 5, 45);

    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", vector_good[i]);
    }

    int * vector_bad = allocateArray_bad(5, 45);

    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", vector_bad[i]);
    }

	return (0);
}	/* main() */