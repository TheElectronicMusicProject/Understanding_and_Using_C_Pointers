#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (void)
{
	char * name;

    printf("Enter a name: ");
    scanf("%s", name);

    printf("%s\n", name);

	return (0);
}	/* main() */