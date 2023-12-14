#include "lists.h"

/**
 * free_nodes - Frees nodes in the stack.
 * @stack: Pointer to the stack.
 */
void free_nodes(stack_t **stack)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

/**
 * is_numeric - Checks if a string represents a numeric value.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str) && *str != '-')
			return (0); /* Not numeric */
		str++;
	}
	return (1); /* Numeric */
}

/**
 * parse_and_execute_opcode - Parses and executes the Monty bytecode opcode.
 * @stack: A pointer to a pointer to the stack.
 * @line: The current line of Monty bytecode.
 * @line_number: The current line number.
 *
 * Return: void
 */
void parse_and_execute_opcode(stack_t **stack,
							  char *line, unsigned int line_number)
{
	char *opcode, *arg;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", _div}, {"mul", mul},
		{"mod", mod}, {"#", nop}, {NULL, NULL}};

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return; /* Ignore empty lines and comments */

	arg = strtok(NULL, " \t\n");
	if (strcmp(opcode, "push") == 0)
	{
		if (!arg || !is_numeric(arg))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(arg));
	}
	else
	{
		int i = 0;

		while (instructions[i].opcode)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, line_number);
				return;
			}
			i++;
		}
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
