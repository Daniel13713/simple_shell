#include "duriv.h"

/**
 * tokennizer - function that split the line
 *
 * @line: user delivered line
 * Return: tokens
 *
 */

char **tokennizer(char *line)
{
	int buff = GLOBAL_BUFSIZE, oldbuff = 0, pos = 0;
	char **tokens;
	char *token;

	tokens = malloc(buff * sizeof(char *));
	if (!tokens)
	{
		goto error;
	}

	token = strtok(line, GLOBAL_DELIMITERS);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= buff)
		{
			oldbuff = buff;
			buff += GLOBAL_BUFSIZE;
			tokens = _realloc(tokens, oldbuff * sizeof(char *), buff * sizeof(char *));
			if (!tokens)
			{
				goto error; /*CAN BE USED?*/
			}
		}
		token = strtok(NULL, GLOBAL_DELIMITERS);
	}
	tokens[pos] = NULL;
	return (tokens);
error:
	free(line);
	free(tokens);
	perror("Alocation error\n"); /*CAN BE USED?*/
	exit(EXIT_FAILURE);
}
