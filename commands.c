#include "monty.h"

/**
 * push - pushes an element to the stack
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
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

/**
 * pall - prints all the values on the stack, starting from the top
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
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

/**
 * pint - prints the value at the top of the stack
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
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

/**
 * swap - swaps the top two elements of the stack
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
void	swap(stack_t **stack, unsigned int line_number)
{
	stack_t	*n1;
	stack_t	*n2;
	stack_t	*buf;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
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

/**
 * nop - doesn’t do anything
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
void	nop(stack_t **stack, unsigned int line_number)
{
	;
}

/**
 * div_op - divides the second top element of the stack by \
 the top element of the stack and remove the first element
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
void	div_op(stack_t **stack, unsigned int line_number)
{
	stack_t	*n1;
	stack_t	*n2;
	stack_t	*buf;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	n1 = *stack;
	if (n1->n == 0)
	{
		fprintf(stderr, "L%u: : division by zero\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	n2 = n1->next;
	n2->n = n2->n / n1->n;
	delete_node(stack, n1);
}

/**
 * mod_op - computes the rest of the division of the second top element \
 of the stack by the top element of the stack and deletes the first elem
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
void	mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t	*n1;
	stack_t	*n2;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	n1 = *stack;
	if (n1->n == 0)
	{
		fprintf(stderr, "L%u: : division by zero\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	n2 = n1->next;
	n2->n = n2->n % n1->n;
	delete_node(stack, n1);
}

/**
 * pchar - prints the char at the top of the stack
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
void	pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	if (!isascii((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * rotl - rotate the first element of the stack to the end
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
void	rotl(stack_t **stack, unsigned int line_number)
{
	stack_t	*buf;

	buf = *stack;
	if (buf)
	{
		if (buf->next)
			buf->next->prev = NULL;
		add_node_end(stack, buf);
		*stack = buf->next;
		buf->next = NULL;
	}
}
