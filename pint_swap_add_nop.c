#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * nop - Does nothing.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
