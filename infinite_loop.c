#include "duriv.h"

/**
 * infinite_loop - mean infinite loop
 *
 * Return: Nothing
 */

void infinite_loop(char *input)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1, iterations = 0;

	do {
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		line = reader();
		args = tokennizer(line);
		status = executer(args);
		iterations++;
		if (status == 2)
		{
			write(STDOUT_FILENO, input, 8);
		}
		free(line);
		free(args);
	} while (status);

}
