#include <stdio.h>
#include <stdint.h>

int
main (void)
{
	short s = 0;
    short * ps = &s;
    char c = 0;
    char * pc = &c;
    int num = 5;
    void * pv = &num;

    printf("Content of ps before: %p\n", ps);
    ps = ps + 1;
    printf("Content of ps after: %p\n", ps);

    printf("Content of pc before: %p\n", pc);
    pc = pc + 1;
    printf("Content of pc after: %p\n", pc);

    printf("Content of pv before: %p\n", pv);
    pv = pv + 1;
    printf("Content of pv after: %p\n", pv);
	
	return (0);
}	/* main() */