#include <stdio.h>

int
main (void)
{
	int num = 5;
    const int limit = 500;
    int * pi;
    const int * pci;

    pi = &num;
    pci = &limit;

    printf("  num -\tAddress: %p\t value: %d\n", &num, num);
    printf("limit -\tAddress: %p\t value: %d\n", &limit, limit);
    printf("   pi -\tAddress: %p\t value: %p\n", &pi, pi);
    printf("  pci -\tAddress: %p\t value: %p\n", &pci, pci);

    printf("%d\n", *pci);

    pci = &num;

    printf("%d\n", *pci);
#if 0
    *pci = 32;
#endif
	return (0);
}	/* main() */