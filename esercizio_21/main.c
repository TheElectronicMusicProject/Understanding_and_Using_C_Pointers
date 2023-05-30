#include <stdio.h>
#include <stdlib.h>

float
average (int * arr, int size)
{
    int sum = 0;

    printf("arr: %p\n", &arr);
    printf("size: %p\n", &size);
    printf("sum: %p\n", &sum);

    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return (sum * 1.0f) / size;
}

int
main (void)
{
    int array[5] = {1, 2, 3, 5, 7};

    printf("Valore medio = %f", average(array, 5));

	return (0);
}	/* main() */