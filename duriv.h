#ifndef _DURIV_H_
#define _DURIV_H_

/*Global variables*/
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

/* Prototypes */
void infinite_loop(void);
char *reader(void);
char **tokennizer(char *line);
int executer(char **args);


/*Help Funtions*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif
