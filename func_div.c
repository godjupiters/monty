#include "monty.h"

/**
 * func_f_div - function that divide two elements of stack.
 * @head: variable holding head
 * @count: variable holding the counter
 * Return: 0
*/

void func_f_div(stack_top **head, unsigned int count)
{
	stack_top *h;
	int lent = 0, imp;

	h = *head;
	while (h)
	{
		h = h->next;
		lent++;
	}
	if (lent < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	imp = h->next->n / h->n;
	h->next->n = imp;
	*head = h->next;
	free(h);
}
