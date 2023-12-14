#include "monty.h"
#include <stdio.h>

/**
 * main - function that loads the app
 * @argv: variable holding the list of argument
 * @argc: variable holding the argument count
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	func_open_file(argv[1]);
	func_free_nodes();
	return (0);
}

/**
 * func_create_node - function that create new node.
 * @n: variable holding the value for inside the node.
 * Return: node. Otherwise NULL.
 */

stack_t *func_create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		func_err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * func_free_nodes - function that free node in stack.
 */

void func_free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * func_add_to_queue - function that add node to queue
 * @new_node: variable holding the pointer to new node.
 * @count: variable holding the count of the opcode.
 */

void func_add_to_queue(stack_t **new_node,
		__attribute__((unused))unsigned int count)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}
