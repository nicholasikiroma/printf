#include "main.h"

/**
 * print_b - this takes an unsingned integer and converts to binary
 * @b: unsigned integer to print
 *
 * Return: number of digits printed
 */
int print_b(va_list b)
{
	unsigned int x, y, i, sum;
	unsigned int a[32];
	int total;

	x = va_arg(b, unsigned int);
	y = 2147483648;
	a[0] = y / x;
	for (i = 1; i < 32; i++)
	{
		y /= 2;
		a[i] = (x / y) % 2;
	}
	for (i = 0, sum = 0, total = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			_putchar('0' + a[i]);
			total++;
		}
	}
	return (total);
}
