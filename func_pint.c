#include "monty.h"

/**
 * func_f_pint - function that print top
 * @head: variable holding stack_head
 * @count: variable holding count
 * Return: 0
*/

void func_f_pint(stack_top **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
