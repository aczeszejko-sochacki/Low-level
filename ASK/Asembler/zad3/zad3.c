#include<stdio.h>
#include<stdlib.h>

void insert_sort(long *first, long *last);

int main(int argc, char **argv)
{
	if(argc < 2)
		return EXIT_FAILURE;

	long *numbers = malloc((argc - 1) * sizeof(long));

	for (int i = 0; i < argc - 1; i++)
		numbers[i] = strtol(argv[i + 1], NULL, 10);

	long *first = numbers, *last = numbers + argc - 2;
  
  	insert_sort(first, last);

	for (int i = 0; i < argc - 1; i++)
		printf("%ld ", numbers[i]);

	printf("\n");

	free(numbers);
 
	return EXIT_SUCCESS;
}
