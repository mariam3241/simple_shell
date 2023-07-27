#include "shell.h"

/**
 * _strncpy - A function that copies a string.
 * @dest: pointer to destination input buffer
 * @src: pointer to source input buffer
 * @n: bytes of @src
 * Return: @dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - a function that concatenates two strings.
 * @dest: pointer to destination input
 * @src: pointer to source input
 * @n: most number of bytes from @src
 * Return: @dest
*/
char *_strncat(char *dest, char *src, int n)
{
	int c, i;
	char *s = dest;

	i = 0;
	c = 0;
	while (dest[i] != '\0')
		i++;
	while (src[c] != '\0' && c < n)
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	if (c < n)
		dest[i] = '\0';
	return (s);
}

/**
 * *_strchr - fills memory with a constant byte.
 * @s: pointer to put the constant
 * @c: constant
 * Return: pointer to s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
