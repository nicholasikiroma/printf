#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * _printf - print output to stdout according to a format string
 * @format: the format of the string to print
 *
 * Return: number of characters printed except the null byte
 */
int _printf(const char *format, ...)
{
	va_list call;
	unsigned int i, length = 0;

	va_start(call, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{   _putchar('%');
				i = i + 1;
				length++;
			}
		}
		else
		{ _putchar(format[i]);
			length++;
		}
	}
	va_end(call);
	return (length);
}
