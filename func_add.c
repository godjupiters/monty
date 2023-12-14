#include "monty.h"

/**
 * func_add - function adds two values of the stack.
 * @head: variable holding the value of stack head
 * @count: variable holding count
 * Return: 0
*/

void func_add(stack_top **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	imp = h->n + h->next->n;
	h->next->n = imp;
	*head = h->next;
	free(h);
}
