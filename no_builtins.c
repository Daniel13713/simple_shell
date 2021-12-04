#include "duriv.h"

/**
  * no_builtin - executes non builtin programs
  *
  * @arg: input from user
  * Return: always 1 to continue the loop.
  */
int no_builtin(char **arg)
{
	struct stat st;
	char *envp[] = {NULL};
	pid_t pid = 0;
	int fail_exc = 0, wait_child; /*dirs = 0, i = 0;*/
	char *path = NULL; /* *delimiter = ":";  *path_token = NULL;*/
	char *messageFile = NULL;

	if (stat(arg[0], &st) != 0)
	{
		path = _which(arg);
		if (!path)
		{
			messageFile = "./hsh: No such file or directory (NO ES ASÍ)";
			printf("%s\n", messageFile);
			return (1);
		}

		arg[0] = path;
		/*arg[0] = malloc(_strlen(path) * sizeof(char));
		if (arg[0] == NULL)
		{
			free(arg[0]);
			free(path);
			exit(EXIT_FAILURE);
		}
		_strcpy(arg[0], path);*/
	}

	pid = fork();
	if (pid == -1)
	{
		printf("fork failed\n");
		return (1);
	}
	else if (pid == 0)
	{
		fail_exc = execve(arg[0], arg, envp);
		if (fail_exc < 0)
		{
			printf("could not execute %s.\n", arg[0]);
			return (1);
		}
	}
	else
	{
		wait(&wait_child);
		free(path);
	}
	return (1);
}
