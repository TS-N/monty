#include "monty.h"

data_t data;

int	main(int ac, char **av)
{
	FILE	*fd = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	monty(fd);
	clean();
	return (0);
}

void	monty(FILE *fd)
{
	instruction_t	inst[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"div", div_op},
		{"mod", mod_op},
		{"pchar", pchar},
		{"rotl", rotl},
		{NULL, NULL}
	};
	char	*cmd = NULL;
	size_t	n = 0;

	/* data_t init */
	data.fd = fd;
	data.in_line = NULL;
	data.arg = NULL;
	data.stack = NULL;
	data.inst = inst;
	data.line_nb = 1;
	/* data_t init end */

	while (getline(&data.in_line, &n, fd) != -1)
	{
		cmd = strtok(data.in_line, " \n");
		data.arg = strtok(NULL, " \n");
		execute(cmd);
		++data.line_nb;
		free(data.in_line);
		data.in_line = NULL;
	}
}
