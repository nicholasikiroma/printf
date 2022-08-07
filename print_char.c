#include <stdlib.h>
#include "main.h"

/**
 * print_c - prints characters
 * @c: character to print
 * Return: 1 on success
 */
int print_c(va_list c)
{
	char cha = (char)va_arg(int, c);

	_putchar(cha);
	return (1);
}

/**
 * print_s - prints a string
 * @s: string to print
 * Return: number of characters printed
 */

int print_s(va_list s)
{
	int indx;
	char *string = va_arg(s, char *);

	if (string == NULL)
		string = "(null)";
	for (indx = 0; string[indx]; indx++)
	{
		_putchar(string[indx]);
	}
	return (indx);
}
