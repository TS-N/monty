#include "monty.h"

/**
  * isnum - finds if a string is a number
  *@s: the string to analyze
  * Return: 1 if is number 0 otherwise
  **/
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
