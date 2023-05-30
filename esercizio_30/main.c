#include <stdio.h>

typedef int (*fptrToSingleInt)(int);
typedef int (*fptrToTwoints)(int, int);

typedef void (*fptrBase)(void);

int add(int, int);

int
add (int num1, int num2)
{
    return (num1 + num2);
}

int
main (void)
{
    fptrToTwoints fptrFirst = add;
    fptrToSingleInt fptrSecond = (fptrToSingleInt) fptrFirst;
    fptrFirst = (fptrToTwoints) fptrSecond;

    printf("%d\n", fptrFirst(5, 6));

    fptrBase basePointer = NULL;
    basePointer = (fptrBase) fptrFirst;
    fptrFirst = (fptrToTwoints) basePointer;

    printf("%d\n", fptrFirst(5, 6));

	return (0);
}	/* main() */