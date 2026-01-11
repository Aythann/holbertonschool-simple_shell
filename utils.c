#include "shell.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	int i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (0);

	i = 0;
	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *dup;
	int i;
	int len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}

/**
 * print_not_found - prints "not found" error message to stderr
 * @cmd: command name
 *
 * Return: void
 */
void print_not_found(char *cmd)
{
	write(2, "./hsh: 1: ", 10);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}
