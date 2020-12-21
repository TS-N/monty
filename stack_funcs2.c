#include "monty.h"

/**
  * is_comment - Tests if line is a comment.
  * @l: A pointer to char representing the start of a line.
  *
  * Return: 1 if the line is a comment.
  *         0 otherwise. 
  */

unsigned int is_comment(char *l)
{
	unsigned int i = 0;

	while (l[i] == ' ')
		i++;
	return (l[i] == '#' ? 1 : 0);
}
