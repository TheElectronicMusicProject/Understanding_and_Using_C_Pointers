#include <stdio.h>

int
main (int argc, char ** argv)
{
    int num = 8;
    int * pi = &num;
    int tmp = 0;

    printf("Before: %p\n", pi);
    tmp = (int) pi;
    pi = (int *) tmp;
    printf("After: %p\n", pi);
    
	return (0);
}	/* main() */