#include "monty.h"

void	clean(void)
{
	free(data.in_line);
	//free_ll(stack);
	fclose(data.fd);
}
