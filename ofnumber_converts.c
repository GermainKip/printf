#include "main.h"

/**
 * conversions- converter function, a clone of itoa
 * @number: number
 * @base: base
 * @flags: argument flags
 * @direct: directives struct
 *
 * Return: string
 */
char *conversions(long int number, int base, int flags, directives *direct)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = number;
	(void)direct;

	if (!(flags & UNSIGNED) && number < 0)
	{
		n = -number;
		sign = '-';

	}
	array = flags & LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * _unsigned - prints unsigned integer numbers
 * @va: argument pointer
 * @direct: the directives struct
 *
 * Return: bytes printed
 */
int _unsigned(va_list va, directives *direct)
{
	unsigned long l;

	if (direct->l)
		l = (unsigned long)va_arg(va, unsigned long);
	else if (direct->h)
		l = (unsigned short int)va_arg(va, unsigned int);
	else
		l = (unsigned int)va_arg(va, unsigned int);
	direct->unsign = 1;
	return (_printnum(conversions(l, 10, UNSIGNED, direct), direct));
}



/**
 * _address - prints address
 * @va: argument pointer
 * @direct: the directives struct
 *
 * Return: bytes printed
 */
int _address(va_list va, directives *direct)
{
	unsigned long int n = va_arg(va, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = conversions(n, 16, UNSIGNED | LOWERCASE, direct);
	*--str = 'x';
	*--str = '0';
	return (_printnum(str, direct));
}
