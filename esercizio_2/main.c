#include <stdio.h>

int
main (void)
{
	int num;
    int * pi = NULL;
    size_t size = sizeof(void *);

    num = 0;
    pi = &num;

    printf("num is %d\n", num);
    printf("pi is %d\n", *pi);
    printf("&num is %p\n", (void *) &num);
    printf("pi is %p\n", (void *) pi);
    printf("&pi is %p\n", (void **) &pi);

    void * pv = pi;
    pi = (int *) pv;

    printf("num is %d\n", num);
    printf("pi is %d\n", *pi);
    printf("&num is %p\n", (void *) &num);
    printf("pi is %p\n", (void *) pi);
    printf("&pi is %p\n", (void **) &pi);

    printf("Size of void pointer is %d", size);
	
	return (0);
}	/* main() */