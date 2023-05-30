#include <stdio.h>
#include <stdlib.h>

void
allocateArray (int ** arr, int size, int value)
{
    *arr = (int *) malloc(size * sizeof(int));

    if (*arr != NULL)
    {
        for (int i = 0; i < size; ++i)
        {
            *(*arr + i) = value;
        }
    }

    return;
}

void
allocateArray_bad (int * arr, int size, int value)
{
    arr = (int *) malloc(size * sizeof(int));

    if (arr != NULL)
    {
        for (int i = 0; i < size; ++i)
        {
            *(arr + i) = value;
        }
    }

    return;
}

int
main (void)
{
    int * vector = NULL;
    allocateArray(&vector, 5, 45);

    printf("%p\n", vector);

    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", vector[i]);
    }

    int * vector_bad = NULL;
    allocateArray_bad(vector_bad, 5, 45);

    printf("%p\n", vector_bad);

    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", vector_bad[i]);
    }

	return (0);
}	/* main() */