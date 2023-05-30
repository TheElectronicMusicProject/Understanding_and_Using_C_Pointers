#include <stdio.h>
#include <string.h>

int
main (void)
{
    char command[16];

    printf("Enter a command: ");
    fgets(command, 16, stdin);
    command[strlen(command) - 1] = '\0';

    if (0 == strcmp(command, "Quit"))
    {
        printf("The command was Quit\n");
    }
    else
    {
        printf("The command was not Quit\n");
    }

    printf("%p", "Quit");

	return (0);
}	/* main() */