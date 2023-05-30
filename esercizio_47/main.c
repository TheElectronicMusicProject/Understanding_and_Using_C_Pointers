#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t
string_length (const char * p_string)
{
    size_t length = 0;

    while (*(p_string++))
    {
        ++length;
    }

    return length;
}

int
main (void)
{
    char simple_array[] = "simple string";
    char * simple_ptr = (char *) malloc(strlen("simple string") + 1);

    strcpy(simple_ptr, "simple string");
    printf("%d\n", string_length(simple_ptr));

    printf("%d\n", string_length(simple_array));
    printf("%d\n", string_length(&simple_array));
    printf("%d\n", string_length(&simple_array[0]));

	return (0);
}	/* main() */