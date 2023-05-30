#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void
display_array1 (int arr[], int size)
{
    for (int idx = 0; idx < size; ++idx)
    {
        printf("%d\n", arr[idx]);
    }

    return;
}

static void
display_array2 (int * arr, int size)
{
    for (int idx = 0; idx < size; ++idx)
    {
        printf("%d\n", arr[idx]);
    }

    return;
}

int
main (void)
{
    int vector[5] = {1, 2, 3, 4 , 5};
    printf("vector = %p\n", vector);
    printf("sizeof(vector) = %d\n", sizeof(vector));

    display_array1(vector, 5);
    display_array2(vector, 5);

	return (0);
}	/* main() */