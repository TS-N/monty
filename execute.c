#include "monty.h"

void	execute(char *cmd)
{
	char	*buf;
	int	i;

	i = 0;
	buf = data.inst[i].opcode;
	while (buf)
	{
		if (strcmp(cmd, buf) == 0)
		{
			data.inst[i].f(&data.stack, data.line_nb);
			break;
		}
		++i;
		buf = data.inst[i].opcode;
	}
	if (!buf)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", data.line_nb, cmd);
		clean();
		exit(EXIT_FAILURE);
	}
}
