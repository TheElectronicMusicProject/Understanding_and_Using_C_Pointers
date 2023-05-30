#include <stdio.h>
#include <stdint.h>

int
main (void)
{
	size_t num = __SIZE_MAX__;
    char c = 1;
    intptr_t * pi = (intptr_t *)(void *) &num;
    uintptr_t * pu = (uintptr_t *)(void *) &c;

    printf("%d\n", num);
    printf("%zu\n", num);

    printf("Size of *char: %d\n", sizeof(char *));
	
	return (0);
}	/* main() */