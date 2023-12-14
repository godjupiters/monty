#include "monty.h"

/**
 * func_f_pop - function that print top
 * @head: variable holding stack_head
 * @count: variable holding count
 * Return: 0
*/

void func_f_pop(stack_top **head, unsigned int count)
{
	stack_top *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
