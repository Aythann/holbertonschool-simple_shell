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

/**
 * linkpath - builds a linked list of PATH directories
 * @path: PATH value
 *
 * Return: pointer to the head of the list, or NULL
 */
list_path *linkpath(char *path)
{
	list_path *head;
	char *token;
	char *tmp;

	if (path == NULL)
		return (NULL);

	head = NULL;
	tmp = _strdup(path);
	if (tmp == NULL)
		return (NULL);

	token = strtok(tmp, ":");
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, ":");
	}
	free(tmp);

	return (head);
}

/**
 * _which - finds a command in the PATH
 * @filename: command to find
 * @head: linked list of PATH directories
 *
 * Return: full path to the command, or NULL if not found
 */
char *_which(char *filename, list_path *head)
{
	char *full;
	int len;

	if (filename == NULL || head == NULL)
		return (NULL);

	while (head != NULL)
	{
		len = _strlen(head->dir) + _strlen(filename) + 2;
		full = malloc(sizeof(char) * len);
		if (full == NULL)
			return (NULL);

		full[0] = '\0';
		_strcat(full, head->dir);
		_strcat(full, "/");
		_strcat(full, filename);

		if (access(full, X_OK) == 0)
			return (full);

		free(full);
		head = head->next;
	}
	return (NULL);
}
