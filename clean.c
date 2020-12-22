#include "monty.h"

/**
  * free_ll - free the stack
  *@head: the first element of the stack
  **/
void	free_ll(stack_t *head)
{
	stack_t		*buf;

	while (head)
	{
		buf = head->next;
		free(head);
		head = buf;
	}
}

/**
  * clean - cleans all to exit
  **/
void	clean(void)
{
	free(data.in_line);
	free_ll(data.stack);
	fclose(data.fd);
}
