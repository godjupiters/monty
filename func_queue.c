#include "monty.h"

/**
 * func_f_queue - function that print the top
 * @head: variable holding stack_head
 * @count: variable holding count
 * Return: 0
*/

void func_f_queue(stack_top **head, unsigned int count)
{
	(void)head;
	(void)count;
	roll.lifi = 1;
}

/**
 * func_addqueue - function that add node to tail of stack
 * @n: variable holding value
 * @head: variable holding head_stack
 * Return: 0
*/

void func_addqueue(stack_top **head, int n)
{
	stack_top *node_new, *imp;

	imp = *head;
	node_new = malloc(sizeof(stack_top));
	if (node_new == NULL)
	{
		printf("Error\n");
	}
	node_new->n = n;
	node_new->next = NULL;
	if (imp)
	{
		while (imp->next)
			imp = imp->next;
	}
	if (!imp)
	{
		*head = node_new;
		node_new->prev = NULL;
	}
	else
	{
		imp->next = node_new;
		node_new->prev = imp;
	}
}
