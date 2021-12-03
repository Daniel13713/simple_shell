#include "duriv.h"

/**
  * reader - Reads the line input from user
  *
  * Return: char* of the line typed by user
  */
char *reader(void)
{
	char *line;
	size_t size = 0;
	ssize_t readsize;


	if ((readsize = getline(&line, &size, stdin)) == -1)
	{
		if (readsize == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Could not read input");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
