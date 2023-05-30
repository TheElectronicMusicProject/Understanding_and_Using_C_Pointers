#include <stdio.h>
#include <stdlib.h>

typedef int (*funcptr)(int);

int
square (int num)
{
    return (num * num);
}

int
main (void)
{
    int n = 5;
    int (*fptr1)(int) = NULL;
    funcptr fptr2 = NULL;

    fptr1 = square;
    /* fptr1 = &square; */
    fptr2 = square;

    printf("%d squared is %d\n", n, fptr1(n));
    printf("%d squared is %d\n", n + 1, fptr2(n + 1));

	return (0);
}	/* main() */