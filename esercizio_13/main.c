#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
	char * chunk = NULL;

    while (1)
    {
        chunk = (char *) malloc(1*1024*1024);
        printf("Allocating %p\n", chunk);
    }

	return (0);
}	/* main() */