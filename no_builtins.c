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
	int fail_exc = 0, wait_child;

	if (stat(arg[0], &st) != 0)
	{
		printf("Arg[0] doesn't exist, concat arg[0] w/ PATH\n");
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
