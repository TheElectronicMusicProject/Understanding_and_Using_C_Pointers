#include <stdio.h>
#include <stdint.h>

int
main (void)
{
	int vector[] = {28, 41, 7};
    int * pi = vector;

    printf("%d\n", *pi);
    pi += 1;
    printf("%d\n", *pi);
    pi += 1;
    printf("%d\n", *pi);
    pi += 1;    // pi punta a se stesso.
    printf("%x\n", *pi);
	
	return (0);
}	/* main() */