#include "monty.h"

/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number (not used)
 * Return: no return
 */

void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	/* Unused counter parameter */
	(void)counter;

	/* Loop through the stack to print the string */
	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		if (current->n == '\0')
			break; /* Break if encountering null byte */

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
