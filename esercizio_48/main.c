#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
format (char * buffer, size_t size, const char * name, size_t quantity, size_t weight)
{
    snprintf(buffer, size, "Item: %s Quantity: %u Weight: %u", name, quantity, weight);

    return buffer;
}

char *
format_1 (char * buffer, size_t size, const char * name, size_t quantity, size_t weight)
{
    char * format_string = "Item: %s Quantity: %u Weight: %u";
    size_t format_string_length = strlen(format_string) - 6;
    size_t name_length = strlen(name);
    size_t length = format_string_length + name_length + 10 + 10 + 1;

    if (NULL == buffer)
    {
        buffer = (char *) malloc(length);
        size = length;
    }

    snprintf(buffer, size, format_string, name, quantity, weight);

    return buffer;
}


int
main (void)
{
    char buffer[40];

    printf("%s\n", format(buffer, sizeof(buffer), "Filippo", 25, 68));
    printf("%s\n", format_1(NULL, 0, "Axle", 25, 45));

	return (0);
}	/* main() */