#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list va;
	char *ptr, *start;
	directives direct = DIRECTIVES_INIT;

	va_start(va, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = (char *)format; *ptr; ptr++)
	{
		directives_init(&direct, va);
		if (*ptr != '%')
		{
			sum += _putchar(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (_flag(ptr, &direct))
		{
			ptr++;
		}
		ptr = _width(ptr, &direct, va);
		ptr = _precision(ptr, &direct, va);
		if (_modifier(ptr, &direct))
			ptr++;
		if (!_specifier(ptr))
			sum += _print_to(start, ptr,
				direct.l || direct.h ? ptr - 1 : 0);
		else
			sum += _printfunc(ptr, va, &direct);
	}
	_putchar(BUFFER_FLUSH);
	va_end(va);
	return (sum);
}
