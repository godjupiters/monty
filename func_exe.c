#include "monty.h"

/**
* func_execute - function that execute opcode
* @stack: variable holding head
* @count: variable holding count
* @file: variable holding poiner to file
* @contnt: variable holding contnt
* Return: 0
*/

int func_execute(char *contnt, stack_top **stack, unsigned int count, FILE *file)
{
	instruction_exe opp[] = {
				{"push", func_f_push}, {"pall", func_f_pall}, {"pint", func_f_pint},
				{"pop", func_f_pop},
				{"swap", func_f_swap},
				{"add", func_add},
				{"nop", func_f_nop},
				{"sub", func_f_sub},
				{"div", func_f_div},
				{"mul", func_f_mul},
				{"mod", func_f_mod},
				{"pchar", func_f_pchar},
				{"pstr", func_f_pstr},
				{"rotl", func_f_rotl},
				{"rotr", func_f_rotr},
				{"queue", func_f_queue},
				{"stack", func_f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *po;

	po = startokk(contnt, " \n\t");
	if (po && po[0] == '#')
		return (0);
	roll.arg = startokk(NULL, " \n\t");
	while (opp[i].opcode && po)
	{
		if (strcmp(po, opp[i].opcode) == 0)
		{	opp[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (po && opp[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, po);
		fclose(file);
		free(contnt);
		func_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
