#include "monty.h"

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_node;

	if (stack_len(*stack) < 2)
		return;
	curr_node = *stack;
	while(curr_node->next)
	{
		curr_node = curr_node->next;
	}
	curr_node->prev->next = NULL;
	curr_node->prev = NULL;
	curr_node->next = *stack;
	*stack = curr_node;
}
