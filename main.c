#include "monty.h"

data_t data;

/**
  * main - takes a monty byte code as input and interprets it
  * @ac: the number of arguments
  * @av: the list of arguments
  * Return: always 0
  **/
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

/**
  * monty - our main loop; parser and dispatcher
  * @fd: the stream to read from
  **/
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
		{"mul", mul},
		{"div", div_op},
		{"mod", mod_op},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
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
	while (getline(&data.in_line, &n, fd) != -1)
	{
		if (!is_comment(data.in_line))
		{
			cmd = strtok(data.in_line, " \t\n\r");
			data.arg = strtok(NULL, " \t\n\r");
			execute(cmd);
		}
		++data.line_nb;
		free(data.in_line);
		data.in_line = NULL;
	}
}
