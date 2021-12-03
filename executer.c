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
	for (; counter < len_builtins(); counter++)
	{
		if (_strcmp(args[0], builtin_list[counter]) == 0)
		{
			return ((*builtin_exc[i])(arg));
		}
	}
	return (no_builtin(args));
}
