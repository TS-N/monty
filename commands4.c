#include "monty.h"

/**
 * rotr - rotate the last element of the stack to the top
 *@stack: the address of the first element of the stack
 *@line_number: the number of the line read
 **/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_node;

	(void)line_number;
	if (stack_len(*stack) < 2)
		return;
	curr_node = *stack;
	while (curr_node->next)
	{
		curr_node = curr_node->next;
	}
	curr_node->prev->next = NULL;
	curr_node->prev = NULL;
	curr_node->next = *stack;
	(*stack)->prev = curr_node;
	*stack = curr_node;
}
