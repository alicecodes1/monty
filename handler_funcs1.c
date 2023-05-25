#include "monty.h"
#include "lists.h"

/**
<<<<<<< HEAD
 * pint_handler - handles the pint command.
 * @stack: a double pointer  referencing to the stack you want to push to
 * @line_number: the file's line number
=======
 * pint_handler - takes care of the pint instruction.
 * @stack: a double pointer to the stack to which you want to push.
 * @line_number: the line number in the file
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
void pint_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

/**
<<<<<<< HEAD
 * pop_handler - handles the pop instruction
 * @stack: a double pointer to the stack you want to push to.
 * @line_number: the file's line number
=======
 * pop_handler - takes care of the pop instruction
 * @stack: a double pointer to the stack to which you want to push.
 * @line_number: the line number in the file
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
void pop_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
<<<<<<< HEAD
 * swap_handler - handles the swap instruction
 * @stack: a double pointer to the stack you want to push to.
 * @line_number: the file's line number
=======
 * swap_handler - takes care of the swap instruction
 * @stack: a double pointer to the stack to which you want to push.
 * @line_number: the line number in the file
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
void swap_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, num);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
<<<<<<< HEAD
 * add_handler - handles the add command.
 * @stack: a double pointer to the stack you want to push to.
 * @line_number: the file's line number
=======
 * add_handler - takes care of the add command.
 * @stack: a double pointer to the stack to which you want to push.
 * @line_number: the line number in the file
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
void add_handler(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sum = node_0->n + node_1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sum);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
<<<<<<< HEAD
 * nop_handler - handles the nop instruction
 * @stack: a double pointer to the stack you want to push to.
 * @line_number: the file's line number
=======
 * nop_handler - takes care of the nop instruction
 * @stack: a double pointer to the stack to which you want to push.
 * @line_number: the line number in the file
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
void nop_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
<<<<<<< HEAD

=======
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
