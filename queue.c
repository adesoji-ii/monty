#include "monty.h"

/**
 * addqueue - adds a node to the end of the stack (queue behavior)
 * @head: pointer to the head of the stack
 * @n: new value to be added
 * Return: no return
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		handle_error();
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
		return;
	}

	aux = *head;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}

	aux->next = new_node;
	new_node->prev = aux;
}
