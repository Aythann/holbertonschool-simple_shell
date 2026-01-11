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

/**
 * run_builtin - executes a builtin command
 * @argv: arguments array
 *
 * Return: void
 */
void run_builtin(char **argv)
{
	if (_strcmp(argv[0], "exit") == 0)
		exitt(argv);
	else if (_strcmp(argv[0], "env") == 0)
		env(argv);
	else if (_strcmp(argv[0], "cd") == 0)
		cd(argv);
	else if (_strcmp(argv[0], "setenv") == 0)
		_setenv(argv);
	else if (_strcmp(argv[0], "unsetenv") == 0)
		_unsetenv(argv);
}

/**
 * exec_direct - executes a command using direct path (only if contains '/')
 * @argv: arguments array
 *
 * Return: exit status on success, -1 if not a direct path or not executable
 */
int exec_direct(char **argv)
{
	pid_t pid;
	int status;
	int i = 0;

	while (argv[0][i] != '\0')
	{
		if (argv[0][i] == '/')
			break;
		i++;
	}
	if (argv[0][i] == '\0')
		return (-1);

	if (access(argv[0], X_OK) != 0)
		return (-1);

	pid = fork();
	if (pid == 0)
		execve(argv[0], argv, environ);

	if (wait(&status) == -1)
		return (0);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (0);
}

/**
 * exec_path - executes a command using PATH
 * @argv: arguments array
 *
 * Return: exit status on success, 127 if not found
 */
int exec_path(char **argv)
{
	pid_t pid;
	int status;
	char *path;
	list_path *plist;

	path = _getenv("PATH");
	if (path == NULL || path[0] == '\0')
	{
		print_not_found(argv[0]);
		return (127);
	}

	plist = linkpath(path);
	path = _which(argv[0], plist);
	free_list(plist);

	if (path == NULL)
	{
		print_not_found(argv[0]);
		return (127);
	}

	pid = fork();
	if (pid == 0)
		execve(path, argv, environ);

	free(path);

	if (wait(&status) == -1)
		return (0);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (0);
}

/**
 * execute - executes a command
 * @argv: arguments array
 *
 * Return: status code
 */
int execute(char **argv)
{
	int status;

	if (argv == NULL || argv[0] == NULL)
		return (0);

	if (is_builtin(argv))
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			run_builtin(argv);
			return (g_status);
		}

		run_builtin(argv);
		g_status = 0;
		return (0);
	}

	status = exec_direct(argv);
	if (status != -1)
	{
		g_status = status;
		return (status);
	}

	status = exec_path(argv);
	g_status = status;
	return (status);
}
