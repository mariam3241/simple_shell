#include "shell.h"

/**
 * add_node - a fun that adds a node to the start of the list
 * @head: parameter
 * @str: parameter
 * @data: parameter
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int data)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->data = data;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - a fun that adds a node to the end of the list
 * @head: parameter
 * @str: parameter
 * @data: parameter
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int data)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->data = data;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @ptr: parameter
 * Return: size of list
 */
size_t print_list_str(const list_t *ptr)
{
	size_t i = 0;

	while (ptr)
	{
		_puts(ptr->str ? ptr->str : "(nil)");
		_puts("\n");
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/**
 * delete_specificnode - a fun that deletes node at given index
 * @head: parameter
 * @index: parameter
 * Return: an int value
 */
int delete_specificnode(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * freelist - a fun that frees a list
 * @firstnode: parameter
 */
void freelist(list_t **firstnode)
{
	list_t *node, *next_node, *head;

	if (!firstnode || !*firstnode)
		return;
	head = *firstnode;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*firstnode = NULL;
}
