#include "duriv.h"

/**
 * _strlen - return the length of a string
 *
 * @s: pointer to string
 * Return: Length of a string
 */

int _strlen(char *s)
{
	int i;

	if (s == NULL)
	{
		return (0);
	}
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
  * _strcmp - comparing two strings
  *
  * @s1: String to compare
  * @s2: String to compare
  *
  * Return: result
  */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * *_strcpy - Write a function that copies the string
 * pointed to by src, including the
 * terminating null byte (\0), to the buffer
 * pointed to by dest.
 *
 * @dest: varible of destine
 * @src: string of the source
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = _strlen(src);
	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * * _strcat - concatec two strings
 *
 * @dest: pointer final concatenect
 * @src: source string to concatenet
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int i, len_src, len_dest;

	len_src = _strlen(src);
	len_dest = _strlen(dest);
	for (i = 0; i < len_src; i++)
	{
		dest[len_dest + i] = src[i];
	}
	return (dest);
}

/**
 * _strdup - duplicate a string with malloc
 *
 * @str: string to duplicate
 * Return: Pointer to string
 */

char *_strdup(char *str)
{
	char *copy;
	int size_str, i = 0;

	if (str == NULL)
	{
		return (0);
	}

	size_str = _strlen(str);
	copy = malloc(size_str + 1 * sizeof(char));
	if (copy == NULL)
	{
		return (0);
	}

	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}
