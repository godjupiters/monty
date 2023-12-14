#include "monty.h"

/**
* func_free_stack - function that frees link_list
* @head: variable holding head of stack
*/

void func_free_stack(stack_top *head)
{
	stack_top *imp;

	imp = head;
	while (head)
	{
		imp = head->next;
		free(head);
		head = imp;
	}
}
