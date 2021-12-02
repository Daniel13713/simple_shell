#ifndef _DURIV_H_
#define _DURIV_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>


void infinite_loop(void);
char *reader(void);
char **tokennizer(char *line);
int executer(char **args);

#endif
