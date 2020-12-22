#include "monty.h"

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

	(void)line_number;
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
