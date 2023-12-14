#include "monty.h"

/**
 * func_print_char - function that print the ascii code
 * @stack: variable holding the pointer to a pointer stack.
 * @count: variable holding the line number of opcode.
 */

void func_print_char(stack_t **stack, unsigned int count)
{
	int code;

	if (stack == NULL || *stack == NULL)
		func_string_err(11, count);
	code = (*stack)->n;
	if (code < 0 || code > 127)
		func_string_err(10, count);
	printf("%c\n", code);
}

/**
 * func_print_str - function that print string
 * @stack: variable holding pointer stack.
 * @count: variable holding the count number of the opcode.
 */

void func_print_str(stack_t **stack, __attribute__((unused))unsigned int count)
{
	int code;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		code = temp->n;
		if (code <= 0 || code > 127)
			break;
		printf("%c", code);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * func_rotl - function that rotates the first node top bottom
 * @stack: variable holding the pointer to a pointer of stack
 * @count: variable holding the count of opcode.
 */

void func_rotl(stack_t **stack, __attribute__((unused))unsigned int count)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * func_rotr - function that rotates the last node to the top.
 * @stack: variable holding the pointer to a pointer of the stack.
 * @count: variable holding the count of the opcode.
 */

void func_rotr(stack_t **stack, __attribute__((unused))unsigned int count)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
