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
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer value
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int result;

	if (s == NULL)
		return (0);

	i = 0;
	sign = 1;
	result = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			break;

		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (result * sign);
}
