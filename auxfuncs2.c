#include "duriv.h"

/**
 * rev_string - Function that reverse a string
 *
 * @s: string
 * Return: Nothing
 */

void rev_string(char *s)
{
	int i, j, k;
	char c[1024];
	char *p = c;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	for (j = i - 1; j >= 0; --j)
	{
		p[i - j - 1] = *(s + j);
	}
	for (k = 0; k <= i - 1; k++)
	{
		s[k] = p[k];
	}
}
/**
 * *_itoa - conert integers to strings
 *
 * @num: integer
 * @str: buffer where the converted number will be saved
 * @base: base of the number
 * Return: the string
 */
char *_itoa(int num, char *str, int base)
{
	int i = 0, isNegative = 0, rem = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	if (num < 0 && base == 10)
	{
		isNegative = 1;
		num = -num;
	}
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	rev_string(str);
	return (str);
}
