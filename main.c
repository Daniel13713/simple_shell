#include "duriv.h"

/**
 * main - main function
 *
 * @argc: number or commands used to start the shell
 * @argv: arguments
 * Return: Always 0 for success
 */
int main(int argc, char **argv)
{
	char *message1 = ": 0: cannot open ";
	char *message2 = ": No such file\n";

	if (argc > 1)
	{
		write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
		write(STDOUT_FILENO, message1, _strlen(message1));
		write(STDOUT_FILENO, argv[1], _strlen(argv[1]));
		write(STDOUT_FILENO, message2, _strlen(message2));
	}
	else
	{
		infinite_loop(argv[0]);
	}
	return (EXIT_SUCCESS);
}
