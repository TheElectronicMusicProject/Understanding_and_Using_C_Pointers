#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
    int * pi = (int *) malloc(sizeof(int));
    *pi = 5;
    printf("*pi: %d\n", *pi);
    free(pi);
    //*pi = 10;
    //printf("*pi: %d\n", *pi);

    int * p1 = (int *) malloc(sizeof(int));
    *p1 = 5;
    fprintf(stderr, "*p1: %d\n", *p1);
    int * p2;
    p2 = p1;
    free(p1);
    *p2 = 10;
    printf("*p2: %d\n", *p2);

	return (0);
}	/* main() */