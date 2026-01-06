#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the variable
 *
 * Return: pointer to the value, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	int len;

	if (name == NULL)
		return (NULL);

	len = _strlen((char *)name);

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, len) == 0 &&
		    environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

/**
 * env - prints the current environment
 * @arv: arguments (unused)
 *
 * Return: void
 */
void env(char **arv)
{
	int i = 0;

	(void)arv;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}

/**
 * _setenv - adds or modifies an environment variable
 * @arv: arguments
 *
 * Return: void
 */
void _setenv(char **arv)
{
	char *new;
	int i = 0;
	int len;

	if (arv[1] == NULL || arv[2] == NULL)
		return;

	len = _strlen(arv[1]);
	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], arv[1], len) == 0 &&
		    environ[i][len] == '=')
		{
			environ[i] = concat_all(arv[1], "=", arv[2]);
			return;
		}
		i++;
	}

	new = concat_all(arv[1], "=", arv[2]);
	environ[i] = new;
	environ[i + 1] = NULL;
}
