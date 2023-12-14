#include "monty.h"

/**
  *func_f_sub- function that sub
  *@head: variable holding the stack_head
  *@count: variable holding the count
  *Return: 0
 */

void func_f_sub(stack_top **head, unsigned int count)
{
	stack_top *imp;
	int inc, nodes;

	imp = *head;
	for (nodes = 0; imp != NULL; nodes++)
		imp = imp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(roll.file);
		free(roll.contnt);
		func_free_stack(*head);
		exit(EXIT_FAILURE);
	}

	imp = *head;
	inc = imp->next->n - imp->n;
	imp->next->n = inc;
	*head = imp->next;
	free(imp);
}
