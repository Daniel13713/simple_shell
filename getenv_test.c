#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *get_envir(const char *name)
{
	int var = 0, val = 0, arg = 0, debugger = 0;
	char *glovar = NULL;

	for (; environ[var] != NULL; var++)
	{
		if (name[0] == environ[var][0])
		{
			while (environ[var][val] == name[arg])
			{
				if (name[arg + 1] == '\0')
				{
					glovar = malloc(strlen(environ[var]) * sizeof(char) + 1);
					if (!glovar)
					{
						printf("failed to allocate");
						exit(EXIT_FAILURE);
					}
					for (val = 0, debugger = arg + 2; environ[var][debugger] != '\0'; val++, debugger++)
					{
						glovar[val] = environ[var][debugger];
					}
					glovar[debugger] = '\0';
					arg = 0;
					val = 0;
					var = 0;
					return (glovar);
				}
				val++;
				arg++;
			}
		}
	}
	return (NULL);
}

int main(void)
{
	char *variable = NULL;
	char *realgetenv = NULL;

	variable = get_envir("PATH");
	realgetenv = getenv("PATH");

	printf("our getenv %s\n", variable);
	printf("real getenv %s\n", realgetenv);
	free(variable);

	return (0);
}

