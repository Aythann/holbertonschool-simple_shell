#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* ========== global ========== */
extern char **environ;

/* ========== utils.c ========== */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
int _atoi(char *s);

/* ========== string_utils.c ========== */
int _strcmp(char *s1, char *s2);

/* ========== parser.c ========== */
char **splitstring(char *str, const char *delim);

/* ========== env.c ========== */
char *_getenv(const char *name);

/**
 * struct list_path - linked list of PATH directories
 * @dir: directory path
 * @next: pointer to the next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *next;
} list_path;

/* ========== path.c ========== */
list_path *add_node_end(list_path **head, char *str);

/* ========== execute.c ========== */
int is_builtin(char **argv);

/* ========== builtins.c ========== */
void exitt(char **arv);

#endif
