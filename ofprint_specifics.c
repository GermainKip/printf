#include "main.h"

/**
 * _printto - prints a range of char addresses
 * @start: starting address
 * @fin: stopping address
 * @except: except address
 *
 * Return: number of bytes printed
 */
int _print_to(char *start, char *fin, char *except)
{
	int sum = 0;

	while (start <= fin)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * _printrev - prints string in reverse
 * @va: string
 * @direct: the directives struct
 *
 * Return: number bytes printed
 */
int _printrev(va_list va, directives *direct)
{
	int len, sum = 0;
	char *str = va_arg(va, char *);
	(void)direct;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * _printrot13 - prints string in rot13
 * @va: string
 * @direct: the directives struct
 *
 * Return: number bytes printed
 */
int _printrot13(va_list va, directives *direct)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(va, char *);
	(void)direct;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
