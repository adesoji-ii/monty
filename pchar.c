#include "monty.h"
#include <ctype.h>

/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		handle_error();
	}

	if (!isprint(h->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		handle_error();
	}

	printf("%c\n", h->n);
}

/* Error handling function */

/**
 * handle_error - handles error conditions and exits the program.
 */

void handle_error(void)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(bus.head);
	exit(EXIT_FAILURE);
}
