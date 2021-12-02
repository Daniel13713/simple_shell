#include "duriv.h"

/**
  * reader - Reads the line input from user
  *
  * Return: char* of the line typed by user
  */
char *reader(void)
{
	char *line;
	ssize_t size = 0, readsize;

	readsize = getline(&line, &size, stdin);

	if (readsize == -1)
	{
		if (readsize == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Could not read input");
		}
	}
	return (line);
}
