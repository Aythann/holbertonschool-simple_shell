#include "shell.h"

/**
 * main - entry point of the simple shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: status
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
		if (interactive)
			_puts("($) ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		argv = splitstring(line, " \n\t\r");
		if (argv && argv[0])
			execute(argv);

		freearv(argv);
		argv = NULL;
	}

	free(line);
	return (0);
}
