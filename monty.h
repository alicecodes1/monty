#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
<<<<<<< HEAD
 * struct stack_s - the doubly linked list representation of a stack (or queue).
 * @n: a positive integer
 * @prev: refers to the preceding member of the stack (or queue).
 * @next: refers to the item on the stack (or queue) after it.
 * Description: The ALX project's doubly linked list node
 * A stack, queue, LIFO, and FIFO structure.
=======
 * struct stack_s - a stack's (or queue's) doubly linked list representation
 * @n: an integer
 * @prev: refers to the stack's (or queue's) preceding element
 * @next: refers to the next item on the stack (or queue).
 *
 * Description: ALX project's doubly linked list node
 * structure for stacks, queues, LIFO, and FIFO.
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
<<<<<<< HEAD
 * instruction_s struct- opcodes  function
 * @opcode: the code for the operation
 * @f: method for handling opcodes
 * Definitions: stack, queues, LIFO, and FIFO.
 * Opcode and function for the ALX project
=======
 * instruction_s struct - opcode and its function
 * @opcode: the operation code
 * @f: opcode handling function
 *
 * Description: stack, queues, LIFO, FIFO
 * ALX project opcode and function
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
<<<<<<< HEAD
 *  struct args_s  - principal argument structure
 * @av: the command line's filename
 * @ac: the total number of arguments from the main function.
 * @line_number: the file's current line number
 * Description: command-line arguments passed to main
 * used in a variety of functions, organized in a struct for clarity.
=======
 * struct args_s - primary argument structure
 * @av: the filename from the command line
 * @ac: total number of arguments from the main
 * @line_number: the current line number in the file
 *
 * Description: command-line arguments supplied to main that are
 * utilized in various functions, arranged in a struct for clarity.
 *
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 */
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_number;
} args_t;

/**
<<<<<<< HEAD
 * struct data_s - external data that can be accessed from functions.
 * @line: the line number in the file
 * @words: previously parsed line
 * @stack: a pointer to a stack
 * @fptr: a file pointer
 * @qflag: flag for a queue or stack
=======
 * struct data_s - external data to be accessed from within functions
 * @line: the file's line
 * @words: line that has been parsed
 * @stack: a stack pointer
 * @fptr: pointer to a file
 * @qflag: queue or stack flag
>>>>>>> a276b32c74361b72a94bfdb9e14bfd04e6a8651b
 *
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT                 \
	{                             \
		NULL, NULL, NULL, NULL, 0 \
	}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

/* main.c */
void monty(args_t *args);

/* get_func.c */
void (*get_func(char **parsed))(stack_t **, unsigned int);
void push_handler(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack, unsigned int line_number);

/* handler_funcs1.c */
void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);

/* handler_funcs2.c */
void sub_handler(stack_t **stack, unsigned int line_number);
void div_handler(stack_t **stack, unsigned int line_number);
void mul_handler(stack_t **stack, unsigned int line_number);
void mod_handler(stack_t **stack, unsigned int line_number);

/* handler_funcs3.c */
void rotl_handler(stack_t **stack, unsigned int line_number);
void rotr_handler(stack_t **stack, unsigned int line_number);
void stack_handler(stack_t **stack, unsigned int line_number);
void queue_handler(stack_t **stack, unsigned int line_number);

/* char.c */
void pchar_handler(stack_t **stack, unsigned int line_number);
void pstr_handler(stack_t **stack, unsigned int line_number);

/* strtow.c */
int count_word(char *s);
char **strtow(char *str);
void free_everything(char **args);

/* free.c */
void free_all(int all);

#endif
