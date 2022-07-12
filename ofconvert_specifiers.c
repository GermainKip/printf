#include "main.h"

/**
 * _hex - prints unsigned hex numbers in lowercase
 * @va: the argument pointer
 * @direct: the parameters struct
 *
 * Return: bytes printed
 */
int _hex(va_list va, directives *direct)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (direct->l)
		l = (unsigned long)va_arg(va, unsigned long);
	else if (direct->h)
		l = (unsigned short int)va_arg(va, unsigned int);
	else
		l = (unsigned int)va_arg(va, unsigned int);

	str = conversions(l, 16, UNSIGNED | LOWERCASE, direct);
	if (direct->hash && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	direct->unsign = 1;
	return (c += _printnum(str, direct));
}

/**
 * _HEX - prints unsigned hex numbers in uppercase
 * @va: the argument pointer
 * @direct: the parameters struct
 *
 * Return: bytes printed
 */
int _HEX(va_list va, directives *direct)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (direct->l)
		l = (unsigned long)va_arg(va, unsigned long);
	else if (direct->h)
		l = (unsigned short int)va_arg(va, unsigned int);
	else
		l = (unsigned int)va_arg(va, unsigned int);

	str = conversions(l, 16, UNSIGNED, direct);
	if (direct->hash && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	direct->unsign = 1;
	return (c += _printnum(str, direct));
}
/**
 * _binary - prints unsigned binary number
 * @va: the argument pointer
 * @direct: the parameters struct
 *
 * Return: bytes printed
 */
int _binary(va_list va, directives *direct)
{
	unsigned int n = va_arg(va, unsigned int);
	char *str = conversions(n, 2, UNSIGNED, direct);
	int c = 0;

	if (direct->hash && n)
		*--str = '0';
	direct->unsign = 1;
	return (c += _printnum(str, direct));
}

/**
 * _octal - prints unsigned octal numbers
 * @va: the argument pointer
 * @direct: the parameters struct
 *
 * Return: bytes printed
 */
int _octal(va_list va, directives *direct)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (direct->l)
		l = (unsigned long)va_arg(va, unsigned long);
	else if (direct->h)
		l = (unsigned short int)va_arg(va, unsigned int);
	else
		l = (unsigned int)va_arg(va, unsigned int);
	str = conversions(l, 8, UNSIGNED, direct);

	if (direct->hash && l)
		*--str = '0';
	direct->unsign = 1;
	return (c += _printnum(str, direct));
}
