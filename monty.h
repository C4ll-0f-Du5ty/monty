#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#define _GNU_SOURCE
#define __USE_GNU
#define _POSIX_C_SOURCE 200809L

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} Mstack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(Mstack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void free_nodes(Mstack_t **stack);
int is_numeric(const char *str);
void parse_and_execute_opcode(Mstack_t **stack, char *line, unsigned int line_number);
void push(Mstack_t **stack, unsigned int value);
void pop(Mstack_t **stack, unsigned int line_number);
void pall(Mstack_t **stack, unsigned int line_number);
void pint(Mstack_t **stack, unsigned int line_number);
void swap(Mstack_t **stack, unsigned int line_number);
void add(Mstack_t **stack, unsigned int line_number);
void nop(Mstack_t **stack, unsigned int line_number);
void sub(Mstack_t **stack, unsigned int line_number);
void _div(Mstack_t **stack, unsigned int line_number);
void mul(Mstack_t **stack, unsigned int line_number);
void mod(Mstack_t **stack, unsigned int line_number);
void pchar(Mstack_t **stack, unsigned int line_number);
void pstr(Mstack_t **stack, unsigned int line_number);
void rotl(Mstack_t **stack, unsigned int line_number);
void rotr(Mstack_t **stack, unsigned int line_number);

#endif
