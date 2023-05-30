#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    int * pv = (int *) malloc(5 * sizeof(int));

    for (int i = 0; i < 5; ++i)
    {
        pv[i] = i + 1;  // *(pv + i) = i + 1;
        printf("@%d is %d\n", i, *(pv + i));
    }

    printf("&pv -> %p\n", &pv);
    printf("pv -> %p\n", pv);

	return (0);
}	/* main() */