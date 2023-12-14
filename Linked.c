#include "lists.h"
#define _GNU_SOURCE
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
#include <stdbool.h>

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
			return (0); /*Not numeric*/
		str++;
	}
	return (1); /*Numeric*/
}

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
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		parse_and_execute_opcode(&stack, line, line_number);
	}

	free(line);
	fclose(file);
	free_nodes(&stack);

	return (0);
}
