#include<stdio.h>
#include<stdlib.h>

unsigned mulf(unsigned a, unsigned b);

int main(int argc, char **argv)
{
	if(argc < 2)
		return EXIT_FAILURE;

	float a_tmp = strtof(argv[1], NULL);
	float b_tmp = strtof(argv[2], NULL);

	unsigned a = *(unsigned *) &a_tmp;
	unsigned b = *(unsigned *) &b_tmp;

	unsigned result = mulf(a, b);
	
	printf("%x\n", result);

	return EXIT_SUCCESS;
}
