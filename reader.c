#include "duriv.h"

/**
  * reader - Reads the line input from user
  *
  * Return: char* of the line typed by user
  */
char *reader(void)
{
	char *line = NULL;
	size_t size = 0;
	int readsize = 0;

	readsize = getline(&line, &size, stdin);
	if (readsize == -1)
	{
		if (readsize == EOF)
		{
			/*printf("inEOF\n");*/
			write(STDOUT_FILENO, "\n", 1);
			size = 0;
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			size = 0;
			free(line);
			perror("Could not read input");
			exit(EXIT_FAILURE);
		}
	}
	readsize = 0;
	size = 0;
	return (line);
}
