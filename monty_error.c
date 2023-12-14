#include "monty.h"

/**
 * func_err - function that print matching error for error code.
 * @error_exp: variable holding the type of errors
 */

void func_err(int error_exp, ...)
{
	va_list ag;
	char *op;
	int l_no;

	va_start(ag, error_exp);
	switch (error_exp)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 10:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 12:
			l_no = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_no, op);
			break;
		case 13:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 14:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	func_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * func_more_err - function that handle error from stack
 * @error_exp: variable holding the type of errors
 */

void func_more_err(int error_exp, ...)
{
	va_list ag;
	char *op;
	int l_no;

	va_start(ag, error_exp);
	switch (error_exp)
	{
		case 15:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 16:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 17:
			l_no = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_no, op);
			break;
		case 18:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	func_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * func_string_err - function that handle string error.
 * @error_exp: variable holding the type of errors
 */

void func_string_err(int error_exp, ...)
{
	va_list ag;
	int l_no;

	va_start(ag, error_exp);
	l_no = va_arg(ag, int);
	switch (error_exp)
	{
		case 19:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_no);
			break;
		case 20:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_no);
			break;
		default:
			break;
	}
	func_free_nodes();
	exit(EXIT_FAILURE);
}
