#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_swap(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		exit(EXIT_FAILURE);
	}

	int temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
