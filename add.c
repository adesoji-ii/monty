#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_add(stack_t **head, unsigned int counter)
{
	/* Check if stack has less than two elements */
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		handle_error();
	}

	int result = (*head)->n + (*head)->next->n;
	(*head)->next->n = result;

	/* Remove the top element */
	stack_t *temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
