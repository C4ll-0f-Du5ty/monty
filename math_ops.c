#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void sub(Mstack_t **stack, unsigned int line_number)
{
	Mstack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void _div(Mstack_t **stack, unsigned int line_number)
{
	Mstack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */
void mul(Mstack_t **stack, unsigned int line_number)
{
	Mstack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
