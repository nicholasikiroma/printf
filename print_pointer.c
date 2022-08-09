#include "main.h"

/**
 * cal_expo - Calculates exponent
 * @base: base of exponent
 * @exponent: exponent of number
 * 
 * Return: Exponet of a number
 */
static unsigned long cal_expo(unsigned int base, unsigned int exponent)
{
	unsigned int indx;
	unsigned long result = base;

	for (indx = 1; indx < exponent; indx++)
	{
		result *= base;
	}
	return (result);
}

/**
 * print_p - prints the address of a pointer
 * @p: Pointer to print
 *
 * Return: number of characters to print
 */
int print_p(va_list p)
{
	unsigned int ad[16];
	unsigned int indx, sum;
	unsigned long k, j;
	int num = 0;
	char *string = "(nil)";

	k = va_arg(p, unsigned long);
	if (k == 0)
	{
		for (indx = 0; string[indx]; indx++)
		{
			_putchar(string[indx]);
			num++;
		}
		return (num);
	}
	_putchar('0');
	_putchar('x');
	num = 2;
	j = cal_expo(16, 15);
	ad[0] = k / j;

	for (indx = 1; indx < 16; indx++)
	{
		j /= 16;
		ad[indx] = (k / j) % 16;
	}
	for (indx = 0, sum = 0; indx < 16; indx++)
	{
		sum += ad[indx];
		if (sum || indx == 15)
		{
			if (ad[indx] < 10)
				_putchar('0' + ad[indx]);
			else
				_putchar('0' + ('a' - ':') + ad[indx]);
			num++;
		}
	}
	return (num);
}

