#include "shell.h"

/**
 * isactive - a fun that returns true if shell is interactive
 * @info: parameter
 * Return: 1 if interactive and 0 otherwise
 */
int isactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * delimeterchar - a fun that checks if character is a delimeter
 * @c: parameter
 * @delimeter: parameter
 * Return: 1 if true and 0 otherwise
 */
int delimeterchar(char c, char *delimeter)
{
	while (*delimeter)
		if (*delimeter++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - a fun that checks for alphabetic character
 *@c: parameter
 *Return: 1 if alphabetic and 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * strtoint - a fun that converts a string to an integer
 * @s: parameter
 * Return: an int value
 */
int strtoint(char *s)
{
	int i = 0;
	unsigned long int output = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			output *= 10;
			output += (s[i] - '0');
			if (output > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (output);
}

/**
 *atoi - a fun that converts a string to an integer
 *@s: parameter
 *Return: an integer value
 */

int atoi(char *s)
{
	int i, sign = 1, flag = 0, x;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		x = -result;
	else
		x = result;

	return (x);
}
