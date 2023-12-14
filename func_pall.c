#include "monty.h"

/**
 * func_f_pall - function that print stack
 * @head: variable holding stack_head
 * @count: variable holding count
 * Return: 0
*/

void func_f_pall(stack_top **head, unsigned int count)
{
	stack_top *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
