#include <stdio.h>

int
main (void)
{
	int num = 5;
    const int limit = 500;
    int * const cpi = &num;
    int * const cp2 = &limit;   /* Not desirable */

    *cpi = limit;
    *cpi = 25;

    printf("  num -\tAddress: %p\t value: %d\n", &num, num);
    printf("limit -\tAddress: %p\t value: %d\n", &limit, limit);
    printf("  cpi -\tAddress: %p\t value: %p\n", &cpi, cpi);

    printf("%d\n", *cpi);
#if 0
    cpi = &limit;
#endif
	return (0);
}	/* main() */