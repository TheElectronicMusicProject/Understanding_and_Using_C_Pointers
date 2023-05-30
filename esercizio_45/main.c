#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (void)
{
    char name[32];
    char * names[30];
    size_t count = 0;

    printf("Enter a name: ");
    scanf("%s", name);
    names[count] = (char *) malloc(strlen(name) + 1);
    strcpy(names[count], name);
    ++count;

	return (0);
}	/* main() */