#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (void)
{
    /* L'array tiene 13 caratteri */
    char header[] = "Media Player";

    /* L'array tiene 13 caratteri */
    char header1[13];

    char * header2 = (char *) malloc(strlen("Media Player") + 1);

    printf("%s\n", header);
    header[2] = 'K';
    printf("%s\n", header);

    strcpy(header1, "Media Player");
    printf("%s\n", header1);

    strcpy(header2, "Media Player");
    printf("%s\n", header2);
    *(header2 + 2) = 'K';
    printf("%s\n", header2);

	return (0);
}	/* main() */