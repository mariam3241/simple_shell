#include "shell.h"

/**
 * errormsg - a fun that prints an error message
 * @info: parameter
 * @error: parameter
 * Return: 0 or -1
 */
void errormsg(info_t *info, char *error)
{
	_eputs(info->fname);
	_eputs(": ");
	printdeci(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(error);
}

/**
 * printdeci - a fun that prints a decimal num
 * @input: parameter
 * @file: parameter
 * Return: an int value
 */
int printdeci(int input, int file)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int abs, data;

	if (file == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		abs = -input;
		__putchar('-');
		count++;
	}
	else
		abs = input;
	data = abs;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (abs / i)
		{
			__putchar('0' + data / i);
			count++;
		}
		data %= i;
	}
	__putchar('0' + data);
	count++;

	return (count);
}

/**
 * convnum - a fun that convert an int into string
 * @num: parameter
 * @base: parameter
 * @flags: parameter
 * Return: a string value
 */
char *convnum(long int num, int base, int flags)
{
	static char *arr;
	static char buffer[50];
	char s = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		s = '-';

	}
	arr = flags & CONV_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (s)
		*--ptr = s;
	return (ptr);
}

/**
 * comments_handeler - a fun that handel comments
 * @address: parameter
 */
void comments_handeler(char *address)
{
	int i;

	for (i = 0; address[i] != '\0'; i++)
		if (address[i] == '#' && (!i || address[i - 1] == ' '))
		{
			address[i] = '\0';
			break;
		}
}
