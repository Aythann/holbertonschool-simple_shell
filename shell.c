#include "shell.h"

/**
 * main - entry point of the simple shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: status code
 */
int main(int ac, char **av)
{
	char *line;
	size_t len;
	ssize_t nread;
	char **argv;
	int interactive;
	int last_status;

	(void)ac;
	(void)av;

	line = NULL;
	len = 0;
	argv = NULL;
	interactive = isatty(STDIN_FILENO);
	last_status = 0;

	while (1)
	{
		if (interactive != 0)
			_puts("($) ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		argv = splitstring(line, " \n\t\r");
		if (argv != NULL && argv[0] != NULL)
			last_status = execute(argv);

		freearv(argv);
		argv = NULL;
	}

	free(line);

	if (interactive == 0)
		return (last_status);

	return (0);
}
