#include "shell.h"

/**
 * exitt - exits the shell
 * @arv: arguments (unused here)
 *
 * Return: void
 */
void exitt(char **arv)
{
	(void)arv;
	g_exit = 1;
}

/**
 * cd - changes the current directory
 * @arv: arguments
 *
 * Return: void
 */
void cd(char **arv)
{
	char *dir;

	if (arv[1] == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
			dir = "/";
	}
	else
	{
		dir = arv[1];
	}

	if (chdir(dir) != 0)
	{
		_puts("hsh: cd: ");
		_puts(dir);
		_puts(": No such file or directory\n");
	}
}
