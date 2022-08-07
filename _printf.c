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
		{NULL, NULL}
	};

	for (ind = 0; pr[ind].typ != NULL)
	{
		if (pr[ind].typ == *format)
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

	if (format == "\0")
		return (-1);

	va_start(call, format);

	while (format[i])
	{
		for (; format[i] != "%" && format[i]; i++)
		{
			_putchar(format[i]);
			length++;
		}
		if (!format[i])
			return (length);
		func = check(&format[i + 1]);
		if (func != "\0")
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
