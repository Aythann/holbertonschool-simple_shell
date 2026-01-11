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
 * exec_direct - executes a command using direct path
 * @argv: arguments array
 *
 * Return: 0 on success, -1 otherwise
 */
int exec_direct(char **argv)
{
	pid_t pid;

	if (access(argv[0], X_OK) != 0)
		return (-1);

	pid = fork();
	if (pid == 0)
		execve(argv[0], argv, environ);

	wait(NULL);
	return (0);
}

/**
 * exec_path - executes a command using PATH
 * @argv: arguments array
 *
 * Return: 0 on success, 127 if not found
 */
int exec_path(char **argv)
{
	pid_t pid;
	char *path;
	list_path *plist;

	path = _getenv("PATH");
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

	wait(NULL);
	free(path);

	return (0);
}

/**
 * execute - executes a command
 * @argv: arguments array
 *
 * Return: status code (0 or 127)
 */
int execute(char **argv)
{
	int status;

	if (argv == NULL || argv[0] == NULL)
		return (0);

	if (is_builtin(argv))
	{
		run_builtin(argv);
		return (0);
	}

	if (exec_direct(argv) == 0)
		return (0);

	status = exec_path(argv);
	return (status);
}
