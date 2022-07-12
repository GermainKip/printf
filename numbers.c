#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * _printnum - prints a number with options
 * @str: the base number as a string
 * @direct: the directives struct
 *
 * Return: chars printed
 */
int _printnum(char *str, directives *direct)
{
	unsigned int i = _strlen(str);
	int negative = (!direct->unsign && *str == '-');

	if (!direct->precision && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		i--;
	}
	if (direct->precision != UINT_MAX)
		while (i++ < direct->precision)
			*--str = '0';
	if (negative)
		*--str = '-';

	if (!direct->minus)
		return (_printnumright(str, direct));
	else
		return (_printnumleft(str, direct));
}

/**
 * _printnumright - prints a number with options
 * @str: the base number as a string
 * @direct: the directives struct
 *
 * Return: chars printed
 */
int _printnumright(char *str, directives *direct)
{
	unsigned int n = 0, negative1, negative2, i = _strlen(str);
	char pad_char = ' ';

	if (direct->zero && !direct->minus)
		pad_char = '0';
	negative1 = negative2 = (!direct->unsign && *str == '-');
	if (negative1 && i < direct->width && pad_char == '0' && !direct->minus)
		str++;
	else
		negative1 = 0;
	if ((direct->plus && !negative2) ||
		(!direct->plus && direct->space && !negative2))
		i++;
	if (negative1 && pad_char == '0')
		n += _putchar('-');
	if (direct->plus && !negative2 && pad_char == '0' && !direct->unsign)
		n += _putchar('+');
	else if (!direct->plus && direct->space && !negative2 &&
		!direct->unsign && direct->zero)
		n += _putchar(' ');
	while (i++ < direct->width)
		n += _putchar(pad_char);
	if (negative1 && pad_char == ' ')
		n += _putchar('-');
	if (direct->plus && !negative2 && pad_char == ' ' && !direct->unsign)
		n += _putchar('+');
	else if (!direct->plus && direct->space && !negative2 &&
		!direct->unsign && !direct->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * _printnumleft - prints a number with options
 * @str: the base number as a string
 * @direct: the directives struct
 *
 * Return: chars printed
 */
int _printnumleft(char *str, directives *direct)
{
	unsigned int n = 0, negative, negative2, i = _strlen(str);
	char pad_char = ' ';

	if (direct->zero && !direct->minus)
		pad_char = '0';
	negative = negative2 = (!direct->unsign && *str == '-');
	if (negative && i < direct->width && pad_char == '0' && !direct->minus)
		str++;
	else
		negative = 0;

	if (direct->plus && !negative2 && !direct->unsign)
		n += _putchar('+'), i++;
	else if (direct->space && !negative2 && !direct->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < direct->width)
		n += _putchar(pad_char);
	return (n);
}
