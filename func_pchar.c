#include "monty.h"

/**
 * func_f_pchar - function that print char top of the stack and \n
 * @head: variable holding head of stack
 * @count: variable holding count
 * Return: 0
*/

void func_f_pchar(stack_top **head, unsigned int count)
{
	stack_top *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 72 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
