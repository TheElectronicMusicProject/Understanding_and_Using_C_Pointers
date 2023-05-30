#include <stdio.h>

typedef int (*fptrOperation)(int, int);

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
mul (int num1, int num2)
{
    return (num1 * num2);
}

int
div (int num1, int num2)
{
    return (num1 / num2);
}

void
initializeOperationsArray (fptrOperation * operations)
{
    operations['+'] = add;
    operations['-'] = sub;
    operations['*'] = mul;
    operations['/'] = div;
}

int
evaluateArray (fptrOperation * operations, char opcode, int num1, int num2)
{
    fptrOperation operation = NULL;
    
    operation = operations[opcode];

    return (operation(num1, num2));
}

int
main (void)
{
    fptrOperation operations[128] = {NULL};
    int (*operations2[128])(int, int) = {NULL};

    initializeOperationsArray(operations);
    initializeOperationsArray(operations2);

    printf("%d\n", evaluateArray(operations, '+', 5, 6));
    printf("%d\n", evaluateArray(operations, '-', 5, 6));
    printf("%d\n", evaluateArray(operations2, '*', 5, 6));
    printf("%d\n", evaluateArray(operations2, '/', 60 , 21));

	return (0);
}	/* main() */