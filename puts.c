#include "main.h"

/**
 * _puts - Prints a string with newline.
 * @str: The string to print.
 *
 * Return: Void.
 */
int _puts(char *str)
{
	char *ch = str;

	while (*str)
		_putchar(*str++);
	return (str - ch);
}
