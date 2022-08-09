#include <stdlib.h>
#include "main.h"

/**
 * print_c - prints characters
 * @c: character to print
 * Return: 1 on success
 */
int print_c(va_list c)
{
	char cha = (char)va_arg(c, int);

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
/**
 * hex_char - Prints a character's ASCII number in uppercase
 * @h: charactee to print
 * Return: number of characters printed
 */
static int hex_char(char h)
{
	char d[2];
	int num;
	char diff = 'A' - ':';

	d[0] = h / 16;
	d[1] = h % 16;
	for (num = 0; num < 2; num++)
	{
		if (d[num] >= 10)
		{
			_putchar('0' + diff + d[num]);
		}
		else
		{
			_putchar('0' + d[num]);
		}
	}
	return (num);
}

/**
 * print_S - prints a string(including non-printable characters)
 * followed by thw ASCII values
 * @S: string to print
 *
 * Return: number of characters printed
 */
int print_S(va_list S)
{
	unsigned int indx;
	int num = 0;
	char *string = va_arg(S, char *);

	if (string == NULL)
		string = "(null)";
	for (indx = 0; string[indx]; indx++)
	{
		if (string[indx] < 32 || string[indx] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			num += 2;
			num += hex_char(string[indx]);
		}
		else
		{
			_putchar(string[indx]);
			num++;
		}
	}
	return (num);
}

/**
 * print_r - prints astring in reverse
 * @r: string to print
 *
 * Return: number of chars printed
 */
int print_r(va_list r)
{
	char *str;
	int i, total = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	{
		_putchar(str[i]);
		total++;
	}
	return (total);
}
