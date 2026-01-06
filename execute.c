#include "shell.h"

/**
 * is_builtin - checks if a command is a builtin
 * @argv: arguments array
 *
 * Return: 1 if builtin, 0 otherwise
 */
int is_builtin(char **argv)
{
	if (argv == NULL || argv[0] == NULL)
		return (0);

	if (_strcmp(argv[0], "exit") == 0)
		return (1);
	if (_strcmp(argv[0], "env") == 0)
		return (1);
	if (_strcmp(argv[0], "cd") == 0)
		return (1);
	if (_strcmp(argv[0], "setenv") == 0)
		return (1);
	if (_strcmp(argv[0], "unsetenv") == 0)
		return (1);

	return (0);
}

