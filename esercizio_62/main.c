#include <stdio.h>
#include <string.h>

int
main (int argc, char ** argv)
{
    int num = 2147483647;
    int * pi = &num;
    short * ps = (short *) pi;

    printf("pi: %p  Value(16): %x   Value(10): %d\n", pi, *pi, *pi);
    printf("ps: %p  Value(16): %hx   Value(10): %hd\n", ps, (unsigned short)*ps, (unsigned short)*ps);

	return (0);
}	/* main() */