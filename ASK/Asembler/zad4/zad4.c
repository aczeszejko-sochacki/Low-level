#include<stdio.h>
#include<stdlib.h>

unsigned long fibonacci(unsigned long n);

int main(int argc, char **argv)
{
	if(argc < 1)
		return EXIT_FAILURE;

	unsigned long n = strtoul(argv[1], NULL, 10);

	unsigned long result = fibonacci(n);
	
	printf("n. fib is %ld\n", result);
	return EXIT_SUCCESS;
}
