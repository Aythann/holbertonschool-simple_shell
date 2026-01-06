#include "shell.h"

/**
 * splitstring - splits a string into an array of words
 * @str: string to split
 * @delim: delimiters
 *
 * Return: pointer to an array of strings, or NULL on failure
 */
char **splitstring(char *str, const char *delim)
{
	char **argv;
	char *token;
	char *tmp;
	int i = 0;
	int count = 0;

	if (str == NULL)
		return (NULL);

	tmp = _strdup(str);
	if (tmp == NULL)
		return (NULL);

	token = strtok(tmp, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(tmp);

	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
		return (NULL);

	token = strtok(str, delim);
	while (token != NULL)
	{
		argv[i] = _strdup(token);
		if (argv[i] == NULL)
		{
			freearv(argv);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * freearv - frees an array of strings
 * @arv: array to free
 *
 * Return: void
 */
void freearv(char **arv)
{
	int i = 0;

	if (arv == NULL)
		return;

	while (arv[i] != NULL)
	{
		free(arv[i]);
		i++;
	}
	free(arv);
}
