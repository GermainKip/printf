#include "main.h"

/**
 * directives_init - clears struct fields and reset buf
 * @direct: the directives struct
 * @va: the argument pointer
 *
 * Return: Void
 */
void directives_init(directives *direct, va_list va)
{
	direct->unsign = 0;

	direct->plus = 0;
	direct->space = 0;
	direct->hash = 0;
	direct->zero = 0;
	direct->minus = 0;

	direct->width = 0;
	direct->precision = UINT_MAX;

	direct->h = 0;
	direct->l = 0;
	(void)va;
}
