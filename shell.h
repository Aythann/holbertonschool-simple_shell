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
extern int g_exit;

/* ========== utils.c ========== */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
char *_strdup(char *str);
int _atoi(char *s);

/* ========== string_utils.c ========== */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, const char *s2, int n);
char *_strcat(char *dest, char *src);
char *concat_all(char *name, char *sep, char *value);

/* ========== parser.c ========== */
char **splitstring(char *str, const char *delim);
void freearv(char **arv);

/* ========== env.c ========== */
char *_getenv(const char *name);
void env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);

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
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);
void free_list(list_path *head);

/* ========== execute.c ========== */
int exec_direct(char **argv);
int exec_path(char **argv);
int execute(char **argv);
int is_builtin(char **argv);
void run_builtin(char **argv);

/* ========== builtins.c ========== */
void exitt(char **arv);
void cd(char **arv);

#endif
