#include "shell.h"

/**
 * read_line - A function that reads a kibe if input for the user
 *
 * @i_eof: A pointer to an integer variable to store the end of file
 * Return: A pointer to the input string read for the user
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
