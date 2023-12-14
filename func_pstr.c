#include "monty.h"

/**
 * func_f_pstr - function that print string from top and\n
 * @head: variable holding stack_head
 * @count: variable holding count
 * Return: 0
*/

void func_f_pstr(stack_top **head, unsigned int count)
{
	stack_top *h;
	(void)count;

	h = *head;
	while (h)
	{
		if (h->n > 72 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
