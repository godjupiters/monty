#include "monty.h"

/**
 * func_nop - function that operates nothing.
 * @stack: variable holding the pointer to a pointer of the stack.
 * @count: variable holding the count of the opcode.
 */

void func_nop(stack_t **stack, unsigned int count)
{
	(void)stack;
	(void)count;
}

/**
 * func_swap_nodes - function that swaps top two elements of stack.
 * @stack: variable holding the point of node of the stack.
 * @count: variable holding the count of the opcode.
 */

void func_swap_nodes(stack_t **stack, unsigned int count)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		func_more_err(8, count, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * func_add_nodes - function that add top two elements of the stack.
 * @stack: variable holding the point of node of the stack.
 * @count: variable holding the count of the opcode.
 */

void func_add_nodes(stack_t **stack, unsigned int count)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		func_more_err(8, count, "add");

	(*stack) = (*stack)->next;
	calc = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * func_sub_nodes - function add top two element of the stack.
 * @stack: variable holding the point of node of the stack.
 * @count: variable holding the count of the opcode.
 */

void func_sub_nodes(stack_t **stack, unsigned int count)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		func_more_err(8, count, "sub");
	(*stack) = (*stack)->next;
	calc = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * func_div_nodes - function that add top two element of stack.
 * @stack: variable holding the point of node of the stack.
 * @count: variable holding the count of the opcode.
 */

void func_div_nodes(stack_t **stack, unsigned int count)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		func_more_err(8, count, "div");
	if ((*stack)->n == 0)
		func_more_err(9, count);
	(*stack) = (*stack)->next;
	calc = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
