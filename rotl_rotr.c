#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void rotl(Mstack_t **stack, unsigned int line_number)
{
	Mstack_t *first, *last;

	(void)line_number; /*Unused parameter*/

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		last = first;

		while (last->next != NULL)
			last = last->next;

		*stack = first->next;
		(*stack)->prev = NULL;
		first->next = NULL;
		first->prev = last;
		last->next = first;
	}
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void rotr(Mstack_t **stack, unsigned int line_number)
{
	Mstack_t *first, *last;

	(void)line_number; /*Unused parameter*/

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;

		while (first->next != NULL)
			first = first->next;

		last = first->prev;
		last->next = NULL;
		first->next = *stack;
		first->prev = NULL;
		(*stack)->prev = first;
		*stack = first;
	}
}
