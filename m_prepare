#include "shell.h"

/**
 * freeptr - a fun that frees a pointer
 * @ptr: parameter
 * Return: 1 or 0
 */
int freeptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}


/**
 * freestr - a fun that frees a string of strings
 * @str: parametr
 */
void freestr(char **str)
{
	char **s = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(s);
}

/**
 **_memset - a fun that fills memory with byte
 *@ptr: parameter
 *@b: parameter
 *@amount: parameter
 *Return: a pointer to the memory area
 */
char *_memset(char *ptr, char b, unsigned int amount)
{
	unsigned int i;

	for (i = 0; i < amount; i++)
		ptr[i] = b;
	return (ptr);
}

/**
 * _realloc - a fun that reallocates a block of memory
 * @ptr: parameter
 * @osize: parameter
 * @nsize: parameter
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int osize, unsigned int nsize)
{
	char *p;

	if (!ptr)
		return (malloc(nsize));
	if (!nsize)
		return (free(ptr), NULL);
	if (nsize == osize)
		return (ptr);

	p = malloc(nsize);
	if (!p)
		return (NULL);

	osize = osize < nsize ? osize : nsize;
	while (osize--)
		p[osize] = ((char *)ptr)[osize];
	free(ptr);
	return (p);
}
