#include "duriv.h"

/**
 * _memcpy - copy n bytes from memory area src to the memory area of dest
 *
 * @dest: this is pointer to the destination array where thw content
 * is to be copied
 * @src: Source that will be copied
 * @n: number of bytes to copy
 * Return: Pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * *_realloc - reallocate memory
 * @ptr: is a pointer to the memory
 * previously allocated with a call to malloc: malloc(old_size)
 * @old_size: is the size, in bytes, of the allocated space for ptr
 * @new_size: is the new size, in bytes of the new memory block
 * Return:
 * If new_size > old_size, the “added” memory should not be initialized
 * If new_size == old_size do not do anything and return ptr
 * If ptr is NULL, then the call is equivalent to malloc(new_size),
 * for all values of old_size and new_size
 * If new_size is equal to zero, and ptr is not NULL, then the
 * call is equivalent to free(ptr). Return NULL
 * Don’t forget to free ptr when it makes sense
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;

	if (!ptr)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
		{
			goto error;
		}
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		goto error;
	}
	else
	{
		if (old_size < new_size)
		{
			new_ptr = malloc(new_size);
			if (!new_ptr)
			{
				goto error;
			}
			new_ptr = _memcpy(new_ptr, ptr, old_size);
			free(ptr);
		}
		else
		{
			new_ptr = ptr;
		}
	}
	return (new_ptr);
error:
	return (NULL);


}
