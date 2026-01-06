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
