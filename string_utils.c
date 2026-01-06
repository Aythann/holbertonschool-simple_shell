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
