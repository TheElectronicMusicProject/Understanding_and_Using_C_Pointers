#include <stdio.h>

int
main (int argc, char ** argv)
{
    char firstName[8] = "1234567";
    char middleName[8] = "1234567";
    char lastName[8] = "1234567";

    middleName[-2] = 'X';
    middleName[0] = 'X';
    middleName[10] = 'X';

    printf("%p  %s\n", firstName, firstName);
    printf("%p  %s\n", middleName, middleName);
    printf("%p  %s\n", lastName, lastName);

	return (0);
}	/* main() */