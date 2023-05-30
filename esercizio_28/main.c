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

fptrOperator
select (char opcode)
{
    fptrOperator fptr = NULL;

    switch (opcode)
    {
        case '+':
            fptr = add;
        break;

        case '-':
            fptr = sub;
        break;
        
        default:
        break;
    }

    return fptr;
}

int
evaluate (char opcode, int num1, int num2)
{
    fptrOperator operation = select(opcode);

    return (operation(num1, num2));
}

int
main (void)
{
    printf("%d\n", evaluate('+', 5 ,6));
    printf("%d\n", evaluate('-', 5 ,6));

	return (0);
}	/* main() */