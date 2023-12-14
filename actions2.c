#include "lists.h"

/**
 * push - Adds a new node to the top of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @value: The integer value to be added to the stack.
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

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
 * pall - Prints all elements in the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The current line number (unused in this function).
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number; /*Unused parameter*/

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * parse_and_execute_opcode - Parses and executes the Monty bytecode opcode.
 * @stack: A pointer to a pointer to the stack.
 * @line: The current line of Monty bytecode.
 * @line_number: The current line number.
 *
 * Return: void
 */
void parse_and_execute_opcode(stack_t **stack, char *line,
							  unsigned int line_number)
{
	char *opcode, *arg;
	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}};
	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return; /*Ignore empty lines and comments*/
	arg = strtok(NULL, " \t\n");
	if (strcmp(opcode, "push") == 0)
	{
		if (!arg || !is_numeric(arg))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE); }
		push(stack, atoi(arg)); }
	else
	{
		int i = 0;

		while (instructions[i].opcode)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, line_number);
				return; }
			i++; }
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE); }}
