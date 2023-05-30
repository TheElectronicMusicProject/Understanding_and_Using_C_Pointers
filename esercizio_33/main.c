#include <stdio.h>
#include <stdlib.h>

char *
get_line (void)
{
    const size_t size_increment = 10;
    char * buffer = malloc(size_increment);
    char * current_position = buffer;
    size_t max_len = size_increment;
    size_t len = 0;
    int character;

    if (NULL == current_position)
    {
        return NULL;
    }

    while (1)
    {
        character= fgetc(stdin);

        if ('\n' == character)
        {
            break;
        }

        if (++len >= max_len)
        {
            size_t current_offset = current_position - buffer;
            char * newbuffer = realloc(buffer, max_len += size_increment);

            if (NULL == newbuffer)
            {
                free(buffer);
                return NULL;
            }
            else
            {
                /* buffer è invalidato */
            }

            current_position = newbuffer + current_offset;
        }

        *current_position++ = character;
    }

    *current_position = '\0';
    return buffer;
}

int
main (void)
{
    char * p_string = get_line();

    printf("hai scritto %s\n", p_string);

    free(p_string);
    p_string = NULL;

	return (0);
}	/* main() */