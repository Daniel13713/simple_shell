#include "duriv.h"

/**
 * infinite_loop - mean infinite loop
 *
 * Return: Nothing
 */

void infinite_loop(void)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;

	do {
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		line = reader();
		args = tokennizer(line);
		/*status = executer(args);*/

		free(line);
		free(args);
	} while (status);

}
