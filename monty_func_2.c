#include "monty.h"

/**
 * func_add_to_stack - function that add node to stack.
 * @new_node: variable holding the pointer to new node.
 * @count: variable holding the count of the opcode.
 */

void func_add_to_stack(stack_t **new_node,
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
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * func_print_stack - function that add node to stack.
 * @stack: variable holding the pointer top node of the stack.
 * @count: variable holding the count the opcode.
 */

void func_print_stack(stack_t **stack, unsigned int count)
{
	stack_t *temp;

	(void) count;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * func_pop_top - function that add a node to stack.
 * @stack: variable holding pointer to stack.
 * @count: variable holding the count of the opcode.
 */

void func_pop_top(stack_t **stack, unsigned int count)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		func_more_err(7, count);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * func_print_top - function that prints node of the stack.
 * @stack: variable holding the pointer of point
 * @count: variable holding the count of the opcode.
 */

void func_print_top(stack_t **stack, unsigned int count)
{
	if (stack == NULL || *stack == NULL)
		func_more_err(6, count);
	printf("%d\n", (*stack)->n);
}
