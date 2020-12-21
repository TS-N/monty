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

int		remove_node(stack_t **head, stack_t *node)
{
	if (node)
	{
		if (node == *head)
		{
			*head = node->next;
			if (node->next)
				node->next->prev = NULL;
		}
		else
		{
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
		}
		free(node);
	}
}
