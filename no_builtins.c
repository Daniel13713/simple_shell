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
	pid_t pid = 0;
	int fail_exc = 0, wait_child;
	char *path = NULL;

	if (stat(arg[0], &st) != 0)
	{
		path = _which(arg);
		if (!path)
		{
			return (2);
		}

		arg[0] = path;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed\n");
		return (1);
	}
	else if (pid == 0)
	{
		fail_exc = execve(arg[0], arg, environ);
		if (fail_exc < 0)
		{
			perror("could not execute %s.\n", arg[0]);
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
