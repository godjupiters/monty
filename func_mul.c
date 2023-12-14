#include "monty.h"

/**
 * func_f_mul - function that multiply top two elements of stack.
 * @head: variable holding stack_head
 * @count: variable holding count
 * Return: 0
*/

void func_f_mul(stack_top **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	imp = h->next->n * h->n;
	h->next->n = imp;
	*head = h->next;
	free(h);
}
