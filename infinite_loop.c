#include "duriv.h"

/**
 * infinite_loop - mean infinite loop
 * @input: the executable filename
 *
 * Return: Nothing
 */

void infinite_loop(char *input)
{
	char *line = NULL, *message1 = ": not found\n";
	char **args = NULL, string[1024];
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
			_itoa(iterations, string, 10);
			write(STDOUT_FILENO, input, _strlen(input));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, string, _strlen(string));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, args[0], _strlen(args[0]));
			write(STDOUT_FILENO, message1, _strlen(message1));
		}
		free(line);
		free(args);
	} while (status);

}
