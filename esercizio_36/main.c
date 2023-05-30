#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    int * arr[5] = {0};

    for (int idx = 0; idx < 5; ++idx)
    {
        arr[idx] = (int *) malloc(sizeof(int));
        *arr[idx] = idx;

        printf("%d @%p (variable @%p)\n", *arr[idx], &arr[idx], arr[idx]);
    }

	return (0);
}	/* main() */