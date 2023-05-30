#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*fptrOperation) (const char *, const char *);

int
compare (const char * s1, const char * s2)
{
    return strcmp(s1, s2);
}

char
tolower (char character)
{
    char ret = 0;

    if (character >= 0x40 && character <= 0x5A)
    {
        ret = character + 0x20;
    }
    else
    {
        ret = character;
    }

    return ret;
}

char *
stringToLower (const char * string)
{
    char * tmp = (char *) malloc(strlen(string) + 1);
    char * start = tmp;

    while (*string != 0)
    {
        *tmp++ = tolower(*string++);
    }

    *tmp = 0;
    return start;
}

int
compareIgnoreCase (const char * s1, const char * s2)
{
    char * t1 = stringToLower(s1);
    char * t2 = stringToLower(s2);
    int result = compare(t1, t2);

    free(t1);
    free(t2);
    t1 = t2 = NULL;

    return result;
}

void
sort (char * array[], int size, fptrOperation operation)
{
    int swap = 1;

    while (swap)
    {
        swap = 0;

        for (int i = 0; i < size - 1; ++i)
        {
            if (operation(array[i], array[i + 1]) > 0)
            {
                swap = 1;
                char * tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
            }
        }
    }
}

void
displayNames (char * names[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%s\t", names[i]);
    }

    printf("\n");
    return;
}

int
main (int argc, char ** argv)
{
    char * name[] = {"Bob", "Ted", "Carol", "Alice", "alice"};
    sort(name, 5, compareIgnoreCase);
    displayNames(name, 5);

	return (0);
}	/* main() */