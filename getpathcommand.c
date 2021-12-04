#include "duriv.h"
#include <stdio.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>


extern char **environ;

char *_which(char **command)
{
	int j = 0, k = 0;
	struct stat st;
	char *token[1024] = {NULL};
	char *address = NULL, *path = NULL, *env_copy = NULL;

	while (environ[k])
	{
		env_copy = malloc(_strlen(environ[k]) * sizeof(char *));
		if (!env_copy)
		{
			free(env_copy);
			exit(EXIT_FAILURE);
		}
		strcpy(env_copy, environ[k]);
		path = strtok(env_copy, "=");
		if (strcmp(path, "PATH") == 0)
		{
			path = strtok(NULL, "\n");
			break;
		}
		free(env_copy);
		k++;
	}
	/*path = _getenv("PATH");*/
	token[j] = strtok(path, ":");
	while (token[j])
	{
		j++;
		token[j] = strtok(NULL, ":");
	}
	address = malloc(1024 * sizeof(char));
	if (!address)
	{
		free(address);
		free(env_copy);
		perror("No allocate");
		exit(-1);
	}
	j = 0;
	while (token[j])
	{	
		strcpy(address, token[j]);
		strcat(address, "/");
		strcat(address, command[0]);
		if (stat(address, &st) == 0)
		{
			free(env_copy);
			return (address);
		}
		j++;
	}
	free(address);
	free(env_copy);
	return (NULL);
}
