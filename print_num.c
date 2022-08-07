#include "main.h"

/**
 * print_i - prints an integer
 * @i: the integer to print
 *
 * Return: number of digits and chars printed
 */
int print_i(va_list i)
{
	int a[10];
	int x, m, n, sum, total;

	n = va_arg(i, int);
	total = 0;
	m = 1000000000;
	a[0] = n / m;
	for (x = 1; x < 10; x++)
	{
		m /= 10;
		a[x] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		total++;
		for (x = 0; x < 10; x++)
			a[x] *= -1;
	}
	for (x = 0, sum = 0; x < 10; x++)
	{
		sum += a[x];
		if (sum != 0 || x == 9)
		{
			_putchar('0' + a[x]);
			total++;
		}
	}
	return (total);
}

/**
 * print_d - prints a decimal
 * @d: the decimal to print
 *
 * Return: number of digits and chars printed
 */
int print_d(va_list d)
{
	int a[10];
	int x, m, n, sum, total;

	n = va_arg(d, int);
	total = 0;
	m = 1000000000;
	a[0] = n / m;
	for (x = 1; x < 10; x++)
	{
		m /= 10;
		a[x] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		total++;
		for (x = 0; x < 10; x++)
			a[x] *= -1;
	}
	for (x = 0, sum = 0; x < 10; x++)
	{
		sum += a[x];
		if (sum != 0 || x == 9)
		{
			_putchar('0' + a[x]);
			total++;
		}
	}
	return (total);
}
