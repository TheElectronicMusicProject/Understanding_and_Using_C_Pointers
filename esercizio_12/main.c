#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
	int * pi = (int *) malloc(sizeof(int));
    char * pc = (char *) malloc(sizeof(char));

    *pi = 5;
    printf("*pi = %d\n", *pi);
    free(pi);
    pi = NULL;

    for (int idx = 0; idx < 8; ++idx)
    {
        pc[idx] = 0;
        printf("ho scritto %d\n", *(pc + idx));
    }

    free(pc);
    pc = NULL;

	return (0);
}	/* main() */