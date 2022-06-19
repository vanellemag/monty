#include "monty.h"
/**
 * main - monty executed function
 * @argc: int
 * @argv: char
 * Return: 1 success or 0 failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r+");
	char *line = NULL;
	size_t len = 0;
	ssize_t lenline;
	char *p[2];
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: moty file");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((lenline = getline(&line, &len, file)) != -1)
	{
		p[0] = strtok(line, " ");
		if (p != NULL)
		{
			if (strncmp(p[0], "push", 4) == 0)
			{
				p[1] = strtok(NULL, " ");
				value = atoi(p[1]);
				push_(&stack, value);
			}
			if (strncmp(p[0], "pall", 4) == 0)
				pall_(&stack);
			if (strncmp(p[0], "pint", 4) == 0)
				pint_(&stack, lenline);
			if (strncmp(p[0], "pop", 3) == 0)
				pop_(&stack, lenline);
		}
	}
	if (line)
		free(line);
	return (0);
}
