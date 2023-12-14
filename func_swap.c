#include "monty.h"

/**
 * func_f_swap - function that add top two elements of stack
 * @head: variable holding stack_head
 * @count: variable holding count
 * Return: 0
*/

void func_f_swap(stack_top **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	imp = h->n;
	h->n = h->next->n;
	h->next->n = imp;
}
