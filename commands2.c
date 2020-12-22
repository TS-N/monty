#include "monty.h"

/**
  * pop - Removes first element of the stack.
  * @stack: A pointer to a pointer to first element of the stack.
  * @line_number: An unsigned int representing the cmd execution line.
  *
  * Return: Nothing.
  */

void	pop(stack_t **stack, unsigned int line_number)
{
	stack_t *old_head = NULL;
	stack_t *new_head = NULL;

	if (!stack)
		return;
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		old_head = *stack;
		new_head = (*stack)->next;
		old_head->next = NULL;
		free(old_head);
		new_head->prev = NULL;
		*stack = new_head;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}

}

/**
  * pstr - prints the string starting at the top of the stack, followed by a
  * new line.
  * @stack: A pointer to a pointer to first element of the stack.
  * @line_number: An unsigned int representing the cmd execution line.
  *
  * Return: Nothing.
  */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t	*buf = 0;

	if (!stack || !*stack)
		return;
	buf = *stack;
	(void)line_number;
	while (buf)
	{
		if (buf->n < 1 || buf->n > 255)
			break;
		printf("%c", buf->n);
		buf = buf->next;
	}
	puts("");
}

/**
  * mul - Multiplies the top two elements of the stack.
  * @stack: A pointer to a pointer to first element of the stack.
  * @line_number: An unsigned int representing the cmd execution line.
  *
  * Return: Nothing.
  */

void	mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (!stack)
		return;
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	second->n = second->n * first->n;
	delete_node(stack, first);
}

/**
  * sub - Substracts the top two elements of the stack.
  * @stack: A pointer to a pointer to first element of the stack.
  * @line_number: An unsigned int representing the cmd execution line.
  *
  * Return: Nothing.
  */

void	sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (!stack)
		return;
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	second->n = second->n - first->n;
	delete_node(stack, first);
}

/**
  * add - Adds the top two elements of the stack.
  * @stack: A pointer to a pointer to first element of the stack.
  * @line_number: An unsigned int representing the cmd execution line.
  *
  * Return: Nothing.
  */

void	add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (!stack)
		return;
	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clean();
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;
	second->n = first->n + second->n;
	delete_node(stack, first);
}
