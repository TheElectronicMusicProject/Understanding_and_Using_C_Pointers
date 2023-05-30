#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * gpi;
/* Non puoi */
/* int * gpi = malloc(sizeof(int)); */

int
main (void)
{
    int * pi = calloc(5, sizeof(int));

    int * ps = malloc(5 * sizeof(int));
    memset(ps, 0, 5 * sizeof(int));

    free(pi);
    pi = NULL;

    free(ps);
    ps = NULL;

    ///////////////////////////////////

    char * string1 = NULL;
    char * string2 = NULL;

    string1 = (char *) malloc(21);
    strcpy(string1, "0123456789ABCDEFGHIL");

    string2 = realloc(string1, 8);
    printf("string1 value: %p [%s]\n", string1, string1);
    printf("string2 value: %p [%s]\n", string2, string2);

    free(string2);
    string1 = NULL;
    string2 = NULL;

    ///////////////////////////////////

    string1 = (char *) malloc(16);
    strcpy(string1, "0123456789AB");
    string2 = realloc(string1, 64);

    printf("string1 value: %p [%s]\n", string1, string1);
    printf("string2 value: %p [%s]\n", string2, string2);

    free(string2);
    string1 = NULL;
    string2 = NULL;

	return (0);
}	/* main() */