#include <stdio.h>

typedef union _conversion
{
    float fNum;
    unsigned int uiNum;
} Conversion;

typedef union _conversion2
{
    float * fNum;
    unsigned int * uiNum;
} Conversion2;

int
isPosive1 (float number)
{
    Conversion conversion = {.fNum = number};
    return ((conversion.uiNum & 0x80000000) == 0);
}

int
isPositive2 (float number)
{
    Conversion2 conversion;
    conversion.fNum = &number;
    return ((*conversion.uiNum & 0x80000000) == 0);
}

int
isPositive3 (float number)
{
    unsigned int * ptrValue = (unsigned int *) &number;
    return ((*ptrValue & 0x80000000) == 0);
}

int
main (int argc, char ** argv)
{
    int num = 0x12345678;
    
    printf("positivo? %d", isPosive1(num));
    
	return (0);
}	/* main() */