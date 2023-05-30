#include <stdio.h>
#include <stdlib.h>

int * gpi;
/* Non puoi */
/* int * gpi = malloc(sizeof(int)); */

int
main (void)
{
    static int * pi;
    /* Non puoi */
	/* static int * pi = malloc(sizeof(int)); */
    pi = malloc(sizeof(int));

    gpi = malloc(sizeof(int));

	return (0);
}	/* main() */