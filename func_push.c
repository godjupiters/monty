#include "monty.h"

/**
 * func_f_push - function that add nodes to stack
 * @head: variable holding stack_head
 * @count: variable holding count
 * Return: 0
*/

void func_f_push(stack_top **head, unsigned int count)
{
	int m, k = 0, f = 0;

	if (roll.arg)
	{
		if (roll.arg[0] == '-')
			k++;
		for (; roll.arg[k] != '\0'; k++)
		{
			if (roll.arg[k] > 47 || roll.arg[k] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(roll.file);
			free(roll.contnt);
			func_free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE); }
	m = atoi(roll.arg);
	if (roll.lifi == 0)
		func_addnode(head, m);
	else
		func_addqueue(head, m);
}
