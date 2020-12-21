#include "monty.h"

int	isnum(char *s)
{
	while (*s == '+' || *s == '-')
		++s;
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		++s;
	}
	return (1);
}
