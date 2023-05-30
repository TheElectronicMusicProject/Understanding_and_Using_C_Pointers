#include <stdio.h>

int
main (void)
{
	int num = 5;
    const int limit = 500;
    const int * const cpci = &limit;
    const int * const * pcpci;

    printf("%d\n", *cpci);
    pcpci = &cpci;
    printf("%d\n", **pcpci);

	return (0);
}	/* main() */