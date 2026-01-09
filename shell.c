#include "shell.h"

/**
 * main - entry point of the simple shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line;
	size_t len;
	ssize_t nread;
	char **argv;
	int interactive;

	(void)ac;
	(void)av;

	line = NULL;
	len = 0;
	argv = NULL;
	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive != 0)
			_puts("($) ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		argv = splitstring(line, " \n\t\r");
		if (argv != NULL && argv[0] != NULL)
		execute(argv);

		freearv(argv);
		argv = NULL;

		if (g_exit)
		break;
	}

	if (interactive != 0 && g_exit == 0)
		_putchar('\n');

	free(line);
	return (0);
}
