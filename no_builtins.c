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
	int fail_exc = 0, wait_child, dirs = 0, i = 0;
	char *path = NULL, *delimiter = ":"; /* *path_token = NULL;*/

	path = malloc(GLOBAL_BUFSIZE * sizeof(char));
	if(!path)
	{
		free(arg);
		free(path);
		exit(EXIT_FAILURE);
	}
	if (stat(arg[0], &st) != 0)
	{
		path = _getenv("PATH");
		printf("%s\n", path);
		while (path[i])
		{
			if(path[i] == *delimiter)
			{
				dirs++;
			}
			i++;
		}
		i = 0;
		printf("n = %d\n", dirs);
		free(path);

		/*path_token = strtok(path, delimiter);
		while (path_token)
		{
			_strcpy()
		}

		printf("Arg[0] doesn't exist, concat arg[0] w/ PATH\n")*/;
		return (1);
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
	}
	return (1);
}
