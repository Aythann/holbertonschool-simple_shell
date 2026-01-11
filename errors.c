#include "shell.h"

/**
 * print_not_found - prints "not found" error message to stderr
 * @cmd: command name
 *
 * Return: void
 */
void print_not_found(char *cmd)
{
	write(2, "./hsh: 1: ", 10);
	write(2, cmd, _strlen(cmd));
	write(2, ": not found\n", 12);
}
