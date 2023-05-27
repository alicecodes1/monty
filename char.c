#define _POSIX_C_SOURCE 200809L 

#include "monty.h"
#include "lists.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * pchar_handler - handles the "pchar" instruction.
 * @stack: a double pointer to the stack that will be accessed.
 * @line_number: the line number of the instruction in the file.
 */
void pchar_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		dprintf(STDERR_FILENO, PCHAR_RANGE, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

/**
 * pstr_handler - handles the "pstr" instruction.
 * @stack: a double pointer to the stack that will be accessed.
 * @line_number: the line number of the instruction in the file.
 */
void pstr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}

	putchar('\n');
}
