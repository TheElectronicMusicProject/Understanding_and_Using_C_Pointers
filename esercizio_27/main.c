#include <stdio.h>

typedef int (*fptrOperator)(int, int);

int
add (int num1, int num2)
{
    return (num1 + num2);
}

int
sub (int num1, int num2)
{
    return (num1 - num2);
}

int
compute (fptrOperator operation, int num1, int num2)
{
    return (operation(num1, num2));
}

int
main (void)
{
    printf("%d\n", compute(add, 5 ,6));
    printf("%d\n", compute(sub, 5 ,6));

	return (0);
}	/* main() */