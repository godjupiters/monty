#include "monty.h"
bus_t roll = {NULL, NULL, NULL, 0};

/**
* main - function for monty interpreter
* @argc: variable holding the no of argument
* @argv: variable holding the file location
* Return: 0 for success
*/

int main(int argc, char *argv[])
{
	char *contnt;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_top *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	roll.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		contnt = NULL;
		read_line = getline(&contnt, &size, file);
		roll.contnt = contnt;
		count++;
		if (read_line > 0)
		{
			func_execute(contnt, &stack, count, file);
		}
		free(contnt);
	}
	func_free_stack(stack);
	fclose(file);
return (0);
}
