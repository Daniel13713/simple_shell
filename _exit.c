#include "duriv.h"

/**
 * dr_exit - exit of the shell
 * @arg: arguments of the line
 * Return: Always 0
 */

int dr_exit(char **arg)
{
	if (!arg[1])
	{
		return (0);
	}
	return (4);
}
