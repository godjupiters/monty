#include "monty.h"

/**
  *func_f_rotr- function that rotate stack to bottom
  *@head: variable holding the head_stack
  *@count: variable holding count
  *Return: 0
 */

void func_f_rotr(stack_top **head, __attribute__((unused)) unsigned int count)
{
	stack_top *dup;

	dup = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (dup->next)
	{
		dup = dup->next;
	}
	dup->next = *head;
	dup->prev->next = NULL;
	dup->prev = NULL;
	(*head)->prev = dup;
	(*head) = dup;
}
