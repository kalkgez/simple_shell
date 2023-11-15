#include "shell.h"

/**
 * _memcpy - A function that copies memory area
 * @newptr: A pointer to the destination memory area
 * @ptr: A pointer to the source memory area
 * @size: The number of bytes to copy
 *
 * Return: void
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int n;

	for (n = 0; n < size; n++)
		char_newptr[n] = char_ptr[n];
}

/**
 * _realloc - A function that reallocates memory block
 * @ptr: A pointer to the previously allocated memory block
 * @old_size: A size of the old memory block
 * @new_size: A size of the new memory block
 *
 * Return: A pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(new, ptr, new_size);
	else
		_memcpy(new, ptr, old_size);

	free(ptr);
	return (new);
}

/**
 * _reallocdp - A function that reallocates a double pointer array
 * @ptr: A pointer to the previously allocated double pointer array
 * @old_size: A size of the old array
 * @new_size: A size of the new array
 *
 * Return: A pointer to the reallocated double pointer array
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new;
	unsigned int n;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	new = malloc(sizeof(char *) * new_size);
	if (new == NULL)
		return (NULL);

	for (n = 0; n < old_size; n++)
		new[n] = ptr[n];

	free(ptr);

	return (new);
}
