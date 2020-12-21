#include "monty.h"

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

void	clean(void)
{
	free(data.in_line);
	free_ll(data.stack);
	fclose(data.fd);
}
