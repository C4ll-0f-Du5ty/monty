#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - Adds a new node to the top of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @value: The integer value to be added to the stack.
 *
 * Return: void
 */
void push(Mstack_t **stack, unsigned int value)
{
	Mstack_t *new_node = malloc(sizeof(Mstack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void pop(Mstack_t **stack, unsigned int line_number)
{
	Mstack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * pall - Prints all elements in the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number (unused in this function).
 *
 * Return: void
 */
void pall(Mstack_t **stack, unsigned int line_number)
{
	Mstack_t *current;

	(void)line_number; /*Unused parameter*/

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
