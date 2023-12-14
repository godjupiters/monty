#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_top;

/**
 * struct bus_s - variables -args, file, line contnt
 * @arg: value
 * @file: pointer to monty file
 * @contnt: line contnt
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *contnt;
	int lifi;
}  bus_t;

extern bus_t roll;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_top **stack, unsigned int line_number);
} instruction_exe;

void func_f_push(stack_top **head, unsigned int number);
void func_f_pall(stack_top **head, unsigned int number);
void func_f_pint(stack_top **head, unsigned int number);
int func_execute(char *contnt, stack_top **head, unsigned int count, FILE *file);
void func_free_stack(stack_top *head);
void func_f_pop(stack_top **head, unsigned int count);
void func_f_swap(stack_top **head, unsigned int count);
void func_add(stack_top **head, unsigned int count);
void func_f_nop(stack_top **head, unsigned int count);
void func_f_sub(stack_top **head, unsigned int count);
void func_f_div(stack_top **head, unsigned int count);
void func_f_mul(stack_top **head, unsigned int count);
void func_f_mod(stack_top **head, unsigned int count);
void func_f_pchar(stack_top **head, unsigned int count);
void func_f_pstr(stack_top **head, unsigned int count);
void func_f_rotl(stack_top **head, unsigned int count);
void func_f_rotr(stack_top **head, __attribute__((unused)) unsigned int count);
void func_addnode(stack_top **head, int z);
void func_addqueue(stack_top **head, int n);
void func_f_queue(stack_top **head, unsigned int count);
void func_f_stack(stack_top **head, unsigned int count);

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *contnt);
#endif
