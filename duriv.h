#ifndef _DURIV_H_
#define _DURIV_H_

/* Global variables */
#define GLOBAL_BUFSIZE 64
#define GLOBAL_DELIMITERS " \t\n"

/* Libraries */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/*Structs*/

/**
 * struct my_builtins - Our printf
 * @command: command passed by user
 * @f: Check
 */
typedef struct my_builtins
{
	char *command;
	int (*f)(char **arg);
} my_builtins;


/* Prototypes */
void infinite_loop(void);
char *reader(void);
char **tokennizer(char *line);
int executer(char **args);
int no_builtin(char **arg);

/*Builtin funtions*/
int dr_exit(char **arg);

/*Builtins list*/
static const my_builtins builtins[] = {
	{"exit", dr_exit},
	/*{"cd", _cd},
	{"help", _help},
	{"env", _env},
	{"setenv", _setenv},
	{"unsetenv", _unsetenv},
	{"alias", _alias},
	{"history", _history}*/
	{NULL, NULL}};

/* Help Funtions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
