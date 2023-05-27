#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include "lists.h"
#include <stdio.h>
/**
<<<<<<< HEAD
 * get_func - selects the proper function
 * @parsed: the bytecode file line sent to main.
 * Return: a pointer to the selected function, or NULL if it fails.
=======
 * get_func - picks the appropriate function
 * @parsed: bytecode file line given to main
 * Return: a reference to the selected function, or NULL if the function fails.
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 *
 */
void (*get_func(char **parsed))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}};

	int codes = 17, i;

	for (i = 0; i < codes; i++)
	{
		if (strcmp(func_arr[i].opcode, parsed[0]) == 0)
		{
			return (func_arr[i].f);
		}
	}
	return (NULL);
}

/**
<<<<<<< HEAD
 * Push_handler - handles the push instruction
 * @stack: a double pointer to the stack you want to push to.
 * @line_number: The file's line number
=======
 * push_handler - takes care of the push instruction
 * @stack: a double pointer to the stack to which you want to push.
 * @line_number: the line number in the file
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
void push_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num = 0, i;

	if (data.words[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data.words[1][i]; i++)
	{
		if (isalpha(data.words[1][i]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(data.words[1]);

	if (data.qflag == 0)
		new = add_dnodeint(stack, num);
	else if (data.qflag == 1)
		new = add_dnodeint_end(stack, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
<<<<<<< HEAD
 *pall_handler - the pall instruction is dealt with by the pall_handler.
 * @stack: is a double-pointer to the stack you want to push.
 * @line_number: the file's line number
=======
 * pall_handler - deals with the pall instruction.
 * @stack: a double pointer to the stack to which you want to push.
 * @line_number: the line number in the file
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
void pall_handler(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}
