#include "monty.h"
#include <ctype.h>

/**
 * is_integer - checks if a string is a valid integer
 * @str: input string
 * Return: 1 if it's an integer, 0 otherwise
 */

int is_integer(const char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_push(stack_t **head, unsigned int counter)
{
	if (bus.arg == NULL || !is_integer(bus.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		handle_error();
	}

	int n = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
