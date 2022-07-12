#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFFER 1024
#define BUFFER_FLUSH -1

#define BUFFER_SIZE 50

#define NULL_STRING "(null)"

#define DIRECTIVES_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define LOWERCASE	1
#define UNSIGNED	2

/**
 * struct parameters - directives struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus: on if plus_flag specified
 * @space: on if hashtag_flag specified
 * @hash: on if _flag specified
 * @zero: on if _flag specified
 * @minu: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h: on if h_modifier is specified
 * @l: on if l_modifier is specified
 *
 */
typedef struct directives
{
	unsigned int unsign	: 1;

	unsigned int plus	: 1;
	unsigned int space	: 1;
	unsigned int hash	: 1;
	unsigned int zero	: 1;
	unsigned int minus	: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h		: 1;
	unsigned int l		: 1;
} directives;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier 
{
	char *specifier;
	int (*f)(va_list, directives *);
} specifier_t;

/* write.c file */
int _puts(char *str);
int _putchar(int c);

/* print.c file */
int _printChar(va_list va, directives *direct);
int _printInt(va_list va, directives *direct);
int _printStr(va_list va, directives *direct);
int _printPercentage(va_list va, directives *direct);
int _printS(va_list va, directives *direct);

/* number_conversions.c file */
char *conversions(long int number, int base, int flags, directives *direct);
int _unsigned(va_list va, directives *direct);
int _address(va_list va, directives *direct);

/* specs.c file */
int (*_specifier(char *s))(va_list va, directives *direct);
int _printfunc(char *s, va_list va, directives *direct);
int _flag(char *s, directives *direct);
int _modifier(char *s, directives *direct);
char *_width(char *s, directives *direct, va_list va);

/* conversions_specifiers.c file */
int _hex(va_list va, directives *direct);
int _HEX(va_list va, directives *direct);
int _binary(va_list va, directives *direct);
int _octal(va_list va, directives *direct);

/* print_specs.c file */
int _print_to(char *start, char *fin, char *except);
int _printrev(va_list va, directives *direct);
int _printrot13(va_list va, directives *direct);

/* numbers.c */
int _isdigit(int c);
int _strlen(char *s);
int _printnum(char *str, directives *direct);
int _printnumright(char *str, directives *direct);
int _printnumleft(char *str, directives *direct);

/* directives.c file */
void directives_init(directives *direct, va_list va);

/* precision.c file */
char *_precision(char *p, directives *direct, va_list va);

/* _prinf.c file */
int _printf(const char *format, ...);

#endif
