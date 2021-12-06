#include "duriv.h"

/**
  * _which - concatenates path to user input
  *
  * @command: user input
  * Return: full function path or NULL if not found
  */
char *_which(char **command)
{
	int j = 0;
	struct stat st;
	char *token[1024] = {NULL};
	char *address = NULL, *path = NULL;

	path = _getenv("PATH");
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
		free(path);
		perror("Unable to allocate");
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
			free(path);
			return (address);
		}
		j++;
	}
	free(path);
	free(address);
	return (NULL);
}
