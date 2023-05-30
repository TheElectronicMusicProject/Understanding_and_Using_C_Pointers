#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (void)
{
	int * pi = (int *) malloc(sizeof(int));
    char * name = (char *) malloc(strlen("Susan") + 1);

    *pi = 5;

    pi = (int *) malloc(sizeof(int));

    strcpy(name, "Susan");
    while (*name != 0)
    {
        printf("%c", *name);
        ++name;
    }

    free(pi);
    pi = NULL;

    free(name);
    name = NULL;

	return (0);
}	/* main() */