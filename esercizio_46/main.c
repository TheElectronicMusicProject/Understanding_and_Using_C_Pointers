#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (void)
{
    char * error = "ERROR: ";
    char * error_message = "Not enough memory";
    char * buffer = (char *) malloc(strlen(error) + strlen(error_message) + 1);

    strcpy(buffer, error);
    strcat(buffer, error_message);

    printf("%s\n", buffer);
    printf("%s @%p\n", error, error);
    printf("%s #%p\n", error_message, error_message);

	return (0);
}	/* main() */