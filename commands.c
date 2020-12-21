#include "monty.h"

void	push(stack_t **stack, unsigned int line_number)
{
	int	a;
	stack_t	*node;

	if (!data.arg || !isnum(data.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", data.line_nb);
		clean();
		exit(EXIT_FAILURE);
	}
	a = atoi(data.arg);
	node = create_node(a);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean();
		exit(EXIT_FAILURE);
	}
	add_node(&data.stack, node);
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

void	pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void	swap(stack_t **stack, unsigned int line_number)
{
	stack_t	*n1;
	stack_t	*n2;
	stack_t	*buf;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too shorti\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	n1 = *stack;
	n2 = n1->next;
	n2->prev = NULL;
	buf = n2->next;
	n2->next = n1;
	n1->prev = n2;
	n1->next = buf;
	*stack = n2;
}
