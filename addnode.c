#include "monty.h"

/**
 * addnode - add node to the head of the stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */

void addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		handle_error();
	}

	aux = *head;

	if (aux != NULL)
		aux->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	*head = new_node;
}
