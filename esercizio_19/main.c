#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
#if 0
    int * pi = (int *) malloc(sizeof(int));
    *pi = 5;
    free(pi);
    free(pi);
#else
    int * p1 = (int *) malloc(sizeof(int));
    *p1 = 5;
    int * p2 = p1;
    free(p1);
    free(p2);
#endif

	return (0);
}	/* main() */