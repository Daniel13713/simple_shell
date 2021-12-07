#include "duriv.h"

/**
  * _getenv - gets value of a given Global Var
  *
  * @name: Variable to analyze
  * Return: Variable value or Null if not find
  */
char *_getenv(char *name)
{
	int var = 0, val = 0, arg = 0;
	char *glovar = NULL;

	for (; environ[var] != NULL; var++)
	{
		if (name[0] == environ[var][0])
		{
			while (environ[var][val] == name[arg])
			{
				if (name[arg + 1] == '\0')
				{
					glovar = malloc(_strlen(environ[var]) * sizeof(char) + 1);
					if (!glovar)
					{
						perror("failed to allocate");
						exit(EXIT_FAILURE);
					}
					for (val = 0, arg = arg + 2; environ[var][arg] != '\0'; arg++, val++)
					{
						glovar[val] = environ[var][arg];
					}
					glovar[val] = '\0';
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
