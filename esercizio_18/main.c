#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    int num = 5;
    int * pi = &num;

    fprintf(stderr, "*pi = %d\n", *pi);

    free(pi);

    fprintf(stderr, "*pi = %d\n", *pi);

	return (0);
}	/* main() */