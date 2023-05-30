#include <stdio.h>

void
add (int size, double * restrict arr1, const double * restrict arr2)
{
    for (int idx = 0; idx < size; ++idx)
    {
        arr1[idx] += arr2[idx];
        printf("arr1[%d] = %lf\n", idx, arr1[idx]);
    }
    
    return;
}

int
main (int argc, char ** argv)
{
    double vector1[] = {1.1, 2.2, 3.3, 4.4};
    double vector2[] = {1.1, 2.2, 3.3, 4.4};

    add(4, vector1, vector2);
    
	return (0);
}	/* main() */