#include "monty.h"

void	do_push(data_t *data, char *arg)
{
	int	a;
	stack_t	*node;

	if (!arg || !isnum(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", data->line_nb);
		clean(data);
		exit(EXIT_FAILURE);
	}
	a = atoi(arg);
	node = create_node(a);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean(data);
		exit(EXIT_FAILURE);
	}
	add_node(&data->stack, node);
}

void	push(stack_t **stack, unsigned int line_number)
{
	printf("In push\n");
}

void	pall(stack_t **stack, unsigned int line_number)
{
	stack_t		*node;

	if (!stack)
		return;
	node = *stack;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

