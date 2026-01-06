#include "shell.h"

/**
 * exitt - exits the shell
 * @arv: arguments (unused here)
 *
 * Return: void
 */
void exitt(char **arv)
{
	if (arv[1] != NULL)
	{
		exit(_atoi(arv[1]));
	}
	else
	{
		exit(0);
	}
}

