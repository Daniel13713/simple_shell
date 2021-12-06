#include "duriv.h"

/**
  * _env - prints the current environment.
  *
  * @args: arguments unused for this function.
  * Return: Always 1
  */
int _env(char **args)
{
	int index = 0;
	(void) args;

	while (environ[index])
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
	return (1);
}
