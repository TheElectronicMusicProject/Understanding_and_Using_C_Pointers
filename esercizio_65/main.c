#include <stdio.h>

int
main (int argc, char ** argv)
{
    int num = 0x12345678;
    char * pc = (char *) &num;

    for (int idx = 0; idx < 4; ++idx)
    {
        printf("%p: %02x \n", pc, (unsigned char) *pc);
        ++pc;
    }
    
	return (0);
}	/* main() */