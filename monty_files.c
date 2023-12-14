#include "monty.h"

/**
 * func_open_file - function to open file
 * @name_of_file: variable holding the file name_path
 * Return: 0
 */

void func_open_file(char *name_of_file)
{
	FILE *fd = fopen(name_of_file, "r");

	if (name_of_file == NULL || fd == NULL)
		func_err(2, name_of_file);

	func_read_file(fd);
	fclose(fd);
}


/**
 * func_read_file - function that read the file
 * @fd: variable holding the pointer to file descriptor
 * Return: void
 */

void func_read_file(FILE *fd)
{
	int count, format = 0;
	char *bffr = NULL;
	size_t len = 0;

	for (count = 1; getline(&bffr, &len, fd) != -1; count++)
	{
		format = func_parse_line(bffr, count, format);
	}
	free(bffr);
}

/**
 * func_parse_line - function that separates each line
 * @bffr: variable holding the line from file
 * @count: variable holding the count of line number
 * @format:  variable holding the stored format
 * Return: 0 if opcode is stack. if queue 1.
 */

int func_parse_line(char *bffr, int count, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (bffr == NULL)
		func_err(4);
	opcode = strtok(bffr, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	func_find_func(opcode, value, count, format);
	return (format);
}

/**
 * func_find_func - function that find appropriate func for the opcode
 * @opcode: variable holding the opcode
 * @value: variable holding the argument of opcode
 * @format:  variable holding the storage format.
 * @count: variable holding the count line_number
 * Return: 0
 */

void func_find_func(char *opcode, char *value, int count, int format)
{
	int i;
	int flgs;

	instruction_t func_list[] = {
		{"push", func_add_to_stack},
		{"pall", func_print_stack},
		{"pint", func_print_top},
		{"pop", func_pop_top},
		{"func_nop", func_nop},
		{"swap", func_swap_nodes},
		{"add", func_add_nodes},
		{"sub", func_sub_nodes},
		{"div", func_div_nodes},
		{"mul", func_mul_nodes},
		{"mod", func_mod_nodes},
		{"pchar", func_print_char},
		{"pstr", func_print_str},
		{"func_rotl", func_rotl},
		{"func_rotr", func_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (flgs = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			func_call_func(func_list[i].f, opcode, value, count, format);
			flgs = 0;
		}
	}
	if (flgs == 1)
		func_err(3, count, opcode);
}


/**
 * func_call_func - function that calls function needed.
 * @func: variable holding the called function.
 * @op: variable holding the string for the opcode.
 * @val: variable holding the string for numeric value.
 * @count: variable holding the count line_numeber.
 * @format: variable holding the format.
 */

void func_call_func(op_func func, char *op, char *val, int count, int format)
{
	stack_t *node;
	int flgs;
	int i;

	flgs = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flgs = -1;
		}
		if (val == NULL)
			func_err(5, count);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				func_err(5, count);
		}
		node = func_create_node(atoi(val) * flgs);
		if (format == 0)
			func(&node, count);
		if (format == 1)
			func_add_to_queue(&node, count);
	}
	else
		func(&head, count);
}
