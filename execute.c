#include "monty.h"

void	execute(char *cmd, char *arg, data_t *data)
{
	char	*buf;
	int	i;

	i = 0;
	buf = data->inst[i].opcode;
	while (buf)
	{
		if (strcmp(cmd, buf) == 0)
		{
			if (strcmp(cmd, "push") == 0)
				do_push(data, arg);
			else
				data->inst[i].f(&data->stack, data->line_nb);
			break;
		}
		++i;
		buf = data->inst[i].opcode;
	}
	if (!buf)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", data->line_nb, cmd);
		clean(data);
		exit(EXIT_FAILURE);
	}
}
