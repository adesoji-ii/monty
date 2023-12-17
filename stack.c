#include "monty.h"

/**
 * f_stack - sets the mode to stack (LIFO)
 * @head: stack head (not used)
 * @counter: line_number (not used)
 * Return: no return
 */

void f_stack(stack_t **head, unsigned int counter)
{
	/* Unused parameters */
	(void)head;
	(void)counter;

	/* Set the mode to stack (LIFO) */
	bus.lifi = 0;
}
