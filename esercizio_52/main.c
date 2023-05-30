#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
blanks (int number)
{
    static char spaces[32] = {0};
    int i = 0;

    for (i = 0; i < number && i < 32; ++i)
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

	return (0);
}	/* main() */