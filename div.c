#include "monty.h"

/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_div(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		handle_error();
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		handle_error();
	}

	int result = (*head)->next->n / (*head)->n;
	(*head)->next->n = result;

	stack_t *temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
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
