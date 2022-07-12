#include "main.h"

/**
 * _precision - gets the precision from the format string
 * @p: format string
 * @direct: the parameters struct
 * @va: the argument pointer
 *
 * Return: new pointer
 */
char *_precision(char *p, directives *direct, va_list va)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(va, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	direct->precision = d;
	return (p);
}
