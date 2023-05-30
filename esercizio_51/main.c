#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
blanks (int number)
{
    char * spaces = (char *) malloc(number + 1);
    int i = 0;

    for (i = 0; i < number; ++i)
    {
        spaces[i] = 'A';
    }

    spaces[number] = '\0';
    return spaces;
}

int
main (int argc, char ** argv)
{
    char * tmp = blanks(5);
    printf("%s\n", tmp);
    free(tmp);
    tmp = NULL;

	return (0);
}	/* main() */