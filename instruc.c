#include "monty.h"

/**
 * func_mul_nodes - function that add top two elements of stack.
 * @stack: variable holding the point of node of the stack.
 * @count: variable holding the count of the opcode.
 */

void func_mul_nodes(stack_t **stack, unsigned int count)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		func_more_err(8, count, "mul");
	(*stack) = (*stack)->next;
	calc = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * func_mod_nodes - function that add top two elements of stack.
 * @stack: variable holding the point of node of the stack.
 * @count: variable holding the count of the opcode.
 */

void func_mod_nodes(stack_t **stack, unsigned int count)
{
	int calc;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		func_more_err(8, count, "mod");
	if ((*stack)->n == 0)
		func_more_err(9, count);
	(*stack) = (*stack)->next;
	calc = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = calc;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
