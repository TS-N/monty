#include "monty.h"

stack_t		*create_node(int n)
{
	stack_t	*node;

	node = malloc(sizeof(stack_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

stack_t		*add_node(stack_t **head, stack_t *node)
{
	if (!head)
		return (NULL);
	if (!*head)
		*head = node;
	else
	{
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
	return (node);
}
