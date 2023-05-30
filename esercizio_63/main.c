#include <stdio.h>

typedef struct _item
{
    int partNumber;
    int quantity;
    int binNumber;
} Item;

int
main (int argc, char ** argv)
{
    Item part = {12345, 35, 107};
    int * pi = &part.partNumber;
    int (*fptrIndirect)(const char *, ...) = printf;

    fptrIndirect("Executing printf indirectly\n");

    printf("Part number: %d\n", *pi);
    ++pi;
    printf("Quantity: %d\n", *pi);
    ++pi;
    printf("Bin number: %d\n", *pi);

    pi = &part.partNumber;
    printf("Part number: %d\n", *pi);
    pi = &part.quantity;
    printf("Quantity: %d\n", *pi);
    pi = &part.binNumber;
    printf("Bin number: %d\n", *pi);

	return (0);
}	/* main() */