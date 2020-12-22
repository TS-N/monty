#include "monty.h"

/**
  * create_node - creates a stack_t node
  * @n: the data of the node
  * Return: the newly created node
  **/
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

/**
  * add_node - add a node at the top of the stack
  * @head: thr address of the head of the linked list
  * @node: the node to add
  * Return: the added node
  **/
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

/**
  * add_node_end - add a node at the bottom of the stack
  * @head: thr address of the head of the linked list
  * @node: the node to add
  * Return: the added node
  **/
stack_t		*add_node_end(stack_t **head, stack_t *node)
{
	stack_t	*buf;

	if (!head)
		return (NULL);
	if (!*head)
		*head = node;
	else
	{
		buf = *head;
		while (buf->next)
			buf = buf->next;
		buf->next = node;
		node->prev = buf;
	}
	return (node);
}

/**
  * delete_node - delete a node of the stack
  * @head: thr address of the head of the linked list
  * @node: the node to remove
  * Return: nothing
  **/
void		delete_node(stack_t **head, stack_t *node)
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

/**
  * stack_len - Computes the number of element in a stack
  * @head: A pointer to the first element of the stack.
  *
  * Return: The size of the stack as a size_t.
  */
size_t stack_len(stack_t *head)
{
	size_t c = 0;

	if (head)
	{
		while (head)
		{
			c++;
			head = head->next;
		}
	}
	return (c);
}
