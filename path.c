#include "shell.h"

/**
 * add_node_end - adds a node at the end of a linked list
 * @head: pointer to the head of the list
 * @str: string to store in the node
 *
 * Return: pointer to the new node, or NULL on failure
 */
list_path *add_node_end(list_path **head, char *str)
{
	list_path *new;
	list_path *tmp;

	if (head == NULL || str == NULL)
		return (NULL);

	new = malloc(sizeof(list_path));
	if (new == NULL)
		return (NULL);

	new->dir = _strdup(str);
	if (new->dir == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new;

	return (new);
}


