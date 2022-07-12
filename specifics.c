#include "main.h"

/**
 * _specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */

int (*_specifier(char *s))(va_list, directives *)
{
	specifier_t specifiers[] = {
		{"c", _printChar},
		{"d", _printInt},
		{"i", _printInt},
		{"s", _printStr},
		{"%", _printPercentage},
		{"b", _binary},
		{"o", _octal},
		{"u", _unsigned},
		{"x", _hex},
		{"X", _HEX},
		{"p", _address},
		{"S", _printS},
		{"r", _printrev},
		{"R", _printrot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}


/**
 * _printfunc - finds the format func
 * @s: the format string
 * @va: argument pointer
 * @direct: the directives struct
 *
 * Return: the number of bytes printed
 */
int _printfunc(char *s, va_list va, directives *direct)
{
	int (*f)(va_list, directives *) = _specifier(s);

	if (f)
		return (f(va, direct));
	return (0);
}

/**
 * _flag - finds the flag func
 * @s: the format string
 * @direct: the directives struct
 *
 * Return: if flag was valid
 */
int _flag(char *s, directives *direct)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = direct->plus = 1;
			break;
		case ' ':
			i = direct->space = 1;
			break;
		case '#':
			i = direct->hash = 1;
			break;
		case '-':
			i = direct->minus = 1;
			break;
		case '0':
			i = direct->zero = 1;
			break;
	}
	return (i);
}

/**
 * _modifier - finds the modifier func
 * @s: the format string
 * @direct: the directives struct
 *
 * Return: if modifier was valid
 */
int _modifier(char *s, directives *direct)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = direct->h = 1;
		break;
	case 'l':
		i = direct->l = 1;
		break;
	}
	return (i);
}

/**
 * _width - gets the width from the format string
 * @s: the format string
 * @direct: the directives struct
 * @va: the argument pointer
 *
 * Return: new pointer
 */
char *_width(char *s, directives *direct, va_list va)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(va, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	direct->width = d;
	return (s);
}
