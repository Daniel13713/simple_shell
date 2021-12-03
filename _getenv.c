#include "duriv.h"
#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

/**
 * _getenv - funtion that gets an environment variable
 *
 * @name: Name of the environment variable
 * Return: Value of the Variable
 */

char *_getenv(char *name)
{
	int k = 0; /* buff = GLOBAL_BUFSIZE;*/
	char **env_copy;
	char *env[1024];

	while (environ[k])
	{
		k++;
	}
	env_copy = malloc(k * sizeof(char *));
	if (!env_copy)
	{
		goto error;
	}
	k = 0;
	while (environ[k])
	{
		env_copy[k] = _strdup(environ[k]);
		env[k] = strtok(env_copy[k], "=");
		if (_strcmp(env[k], name) == 0)
		{	
			env[k + 1] = strtok(NULL, "\n");
			free(env_copy);
			return (env[k + 1]);
		}
		k++;
	}
	return (NULL);
error:
	free(env_copy);
	exit(EXIT_FAILURE);

}
