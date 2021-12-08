#include "duriv.h"

/**
 * _cd - change directory
 *
 * @args: arguments of the line
 * Return: (1) on succes
 */
int _cd(char **args)
{
	char *dir = NULL;

	if (!args[1])
	{
		dir = _getenv("HOME");
		chdir(dir);
		free(dir);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			return (3);
		}
	}
	return (1);
}
