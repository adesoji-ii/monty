#include "monty.h"

/**
 * f_rotr - rotates the stack to the bottom
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */

void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head;
	stack_t *last = NULL;

	/* Unused counter parameter */
	(void)counter;

	/* If the stack is empty or has only one element, no rotation needed */
	if (*head == NULL || (*head)->next == NULL)
		return;

	/* Traverse the stack to find the last element */
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}

	/* Rotate the stack to the bottom */
	current->next = *head;
	*head = current;
	last->next = NULL;
	(*head)->prev = NULL;
}
