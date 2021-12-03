#include "duriv.h"

/**
  * executer - iterates trough args to determine
  * if args are builtin or not
  *
  * @args: array of tokens
  *
  * Return: 1 for no args or call to builtin/non-builtin function
  */
int executer(char **args)
{
	int counter = 0;

	if (args[0] == NULL)
	{
		return (1);
	}
	for (; builtins[counter].command; counter++)
	{
		if (*args[0] == *builtins[counter].command)
		{
			return (builtins[counter].f(args));
		}
	}
	return (10);
}
