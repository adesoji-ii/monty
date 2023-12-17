#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{NULL, NULL}
	};

	char *op = strtok(content, " \n\t");

	if (op == NULL || op[0] == '#')
	{
		return (0);
	}

	char *argument = strtok(NULL, " \n\t");

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: missing argument for %s\n", counter, op);
		handle_error(file, content, *stack);
	}

	unsigned int i = 0;

	while (opst[i].opcode != NULL)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	handle_error(file, content, *stack);
	return (1);
}

/* Error handling function */

/**
 * handle_error - handles error conditions and exits the program.
 * @file: container
 * @content: input
 * @stack: attribute
 */

void handle_error(FILE *file, char *content, stack_t *stack)
{
	fclose(file);
	free(content);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
