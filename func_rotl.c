#include "monty.h"

/**
  *func_f_rotl- function that rotate stack to top
  *@head: variable holding the stack_head
  *@count: variable holding count
  *Return: 0
 */

void func_f_rotl(stack_top **head,  __attribute__((unused)) unsigned int count)
{
	stack_top *tempo = *head, *imp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	imp = (*head)->next;
	imp->prev = NULL;
	while (tempo->next != NULL)
	{
		tempo = tempo->next;
	}
	tempo->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tempo;
	(*head) = imp;
}
