#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * global_header = "Chapter";
char global_array_header[] = "Chapter";

static void
display_header (void)
{
    static char * static_header = "Chapter";
    char * local_header = "Chapter";
    static char static_array_header[] = "Chapter";
    char local_array_header[] = "Chapter";
    char * heap_header = (char *) malloc(strlen("Chapter") + 1);
    strcpy(heap_header, "Chapter");
    return;
}

int
main (void)
{
    display_header();

	return (0);
}	/* main() */