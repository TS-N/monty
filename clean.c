#include "monty.h"

void	clean(data_t *data)
{
	free(data->in_line);
	//free_ll(stack);
	fclose(data->fd);
}
