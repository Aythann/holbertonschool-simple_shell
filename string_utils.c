#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if identical, negative or positive otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (1);

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	return (s1[i] - s2[i]);
}

/**
 * _strncmp - compares two strings up to n characters
 * @s1: first string
 * @s2: second string
 * @n: number of characters to compare
 *
 * Return: 0 if identical, negative or positive otherwise
 */
int _strncmp(char *s1, const char *s2, int n)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL || n <= 0)
		return (1);

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	if (dest == NULL || src == NULL)
		return (dest);

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}

	dest[i + j] = '\0';

	return (dest);
}

/**
 * concat_all - concatenates name, separator and value
 * @name: first string
 * @sep: separator string
 * @value: value string
 *
 * Return: newly allocated string or NULL on failure
 */
char *concat_all(char *name, char *sep, char *value)
{
	char *new;
	int len;

	if (name == NULL || sep == NULL || value == NULL)
		return (NULL);

	len = _strlen(name) + _strlen(sep) + _strlen(value) + 1;
	new = malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);

	new[0] = '\0';
	_strcat(new, name);
	_strcat(new, sep);
	_strcat(new, value);

	return (new);
}
