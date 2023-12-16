#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_mod(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		handle_error();
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		handle_error();
	}

	int result = (*head)->next->n % (*head)->n;
	(*head)->next->n = result;

	stack_t *temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
