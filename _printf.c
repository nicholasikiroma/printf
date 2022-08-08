#include <stdlib.h>
#include "main.h"

/**
 * check - Scans code for valid specifier and calls the appropriate function
 * @format: input format specifier
 * Return: Pointer to specifier function, NULL otherwise
 */

int (*check(const char *format))(va_list)
{
	unsigned int ind;
	print_typ pr[] = {
		{"s", print_s},
		{"c", print_c},
		{"i", print_i},
		{"d", print_d},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"S", print_S},
		{NULL, NULL}
	};

	for (ind = 0; pr[ind].typ != NULL; ind++)
	{
		if (*pr[ind].typ == *format)
		{
			break;
		}
	}
	return (pr[ind].func);
}
/**
 * _printf - print output to stdout according to a format string
 * @format: the format of the string to print
 *
 * Return: number of characters printed except the null byte
 */
int _printf(const char *format, ...)
{
	va_list call;
	unsigned int i = 0, length = 0;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(call, format);

	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			length++;
		}
		if (!format[i])
			return (length);
		func = check(&format[i + 1]);
		if (func != NULL)
		{
			length += func(call);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		length++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(call);
	return (length);
}
