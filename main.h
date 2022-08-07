#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print - Selects data type to print
 * @typ: type of function to print
 * @func: function to call for selected type
 *
 */
typedef struct print
{
	char *typ;
	int (*func)(va_list);
} print_typ;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_b(va_list b);

#endif
