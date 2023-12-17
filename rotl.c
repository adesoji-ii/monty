#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */

void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	stack_t *last_node = *head;

	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}

	last_node->next = *head;
	(*head)->prev = last_node;

	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}
