#include "monty.h"

/**
  * isnum - finds if a string is a number
  *@s: the string to analyze
  * Return: 1 if is number 0 otherwise
  **/
int	isnum(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-')
		++s;
	while (*s)
	{
		if (*s > '9' || *s < '0')
			return (0);
		++s;
	}
	return (1);
}
