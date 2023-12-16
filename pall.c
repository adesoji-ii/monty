#include "monty.h"

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: not used
 * Return: no return
 */

void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	/* Unused counter parameter */
	(void)counter;

	/* If the stack is empty, return */
	if (current == NULL)
		return;

	/* Print each element in the stack */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
