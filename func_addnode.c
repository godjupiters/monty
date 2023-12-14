#include "monty.h"

/**
 * func_addnode - function that add node to head stack
 * @head: variable holding head of stack
 * @z: variable holding value
 * Return: 0
*/

void func_addnode(stack_top **head, int z)
{

	stack_top *node_new, *imp;

	imp = *head;
	node_new = malloc(sizeof(stack_top));
	if (node_new == NULL)
	{ printf("Error\n");
		exit(0); }
	if (imp)
		imp->prev = node_new;
	node_new->z = z;
	node_new->next = *head;
	node_new->prev = NULL;
	*head = node_new;
}
