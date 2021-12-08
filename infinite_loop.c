#include "duriv.h"

/**
 * errors - print errors
 *
 * @status: status of the loop
 * @input: executable filename
 * @args: argumento of the command line
 * @iterations: number of use of the command line
 * Return: Nothing
 */
void errors(int status, char *input, char **args, int iterations)
{
	char *NoCommand = ": not found\n";
	char *noCd = ": cd: can't cd to ";
	char string[1024];

	_itoa(iterations, string, 10);
	if (status == 2)
	{
		write(STDOUT_FILENO, input, _strlen(input));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, string, _strlen(string));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, args[0], _strlen(args[0]));
		write(STDOUT_FILENO, NoCommand, _strlen(NoCommand));
	}
	else if (status == 3)
	{
		write(STDOUT_FILENO, input, _strlen(input));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, string, _strlen(string));
		write(STDOUT_FILENO, noCd, _strlen(noCd));
		write(STDOUT_FILENO, args[1], _strlen(args[1]));
		write(STDOUT_FILENO, "\n", 1);
	}

}

/**
 * action_signal - handle the signal Ctrl+C
 *
 * @sig: number of signal
 * Return: Nothing
 */
void action_signal(int __attribute__((unused))sig)
{
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}

/**
 * infinite_loop - mean infinite loop
 * @input: the executable filename
 *
 * Return: Nothing
 */

void infinite_loop(char *input)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1, iterations = 0;

	do {
		signal(SIGINT, action_signal);
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		line = reader();
		args = tokennizer(line);
		status = executer(args);
		iterations++;
		errors(status, input, args, iterations);

		free(line);
		free(args);
	} while (status);

}
