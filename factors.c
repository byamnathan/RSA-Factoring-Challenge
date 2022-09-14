#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - main entry of the program
 * Find the factors of numbers listed in a file
 * The program read the numbers line by line and compute their factors
 * Numbers less than 0 are skipped
 * @argc: argument count
 * @argv: argumement factor
 * Return: 1 or 0
 */
int main(int argc, char **argv)
{
	FILE *file = NULL;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread = 0;
	int *factors = NULL;
	int factor_size = 10;
	int div;
	int curr_div;
	int i = 0;
	int num;

	if (argc != 2)
		return (0);
	file = fopen(argv[1], "r");
	if (file == NULL)
		return (0);

	factors = malloc(factor_size * sizeof(int));
	if (factors == NULL)
	{
		free(factors);
		return (0);
	}
	while ((nread = getline(&lineptr, &n, file)) != -1)
	{
		num = atoi(lineptr);
		div = 2;
		i = 0;
		curr_div = 2;

		if (num <= 0)
			continue;
		while (div <= num)
		{
			if (num % div == 0)
			{
				factors[i] = div;
				num /= div;
				if (++i > factor_size)
				{
					factor_size += 10;
					factors = realloc(factors, (factor_size * sizeof(int)));
				}
				if (div == curr_div)
					continue;
				else
				{
					curr_div = div;
					continue;
				}
			}
			div++;
		}
		factors[i] = -1;
		num = atoi(lineptr);
		i = 0;
		printf("%d=%d", num, factors[i++]);
		while (factors[i] != -1)
		{
			printf("*%d", factors[i]);
			i++;
		};
		printf("\n");
	}
	free(factors);
	free(lineptr);
	fclose(file);
	return (0);
}
