#include "shell.h"

/**
 * without_comment - A function that removes comments
 * @in: Input string
 * Return: A pointer to the modified string
 */
char *without_comment(char *in)
{
	int n, commentPosition;

	commentPosition = 0;
	for (n = 0; in[n]; n++)
	{
		if (in[n] == '#')
		{
			if (n == 0)
			{
				free(in);
				return (NULL);
			}
			if (in[n - 1] == ' ' || in[n - 1] == '\t' || in[n - 1] == ';')
				commentPosition = n;
		}
	}

	if (commentPosition != 0)
	{
		in = _realloc(in, n, commentPosition + 1);
		in[commentPosition] = '\0';
	}

	return (in);
}

/**
 * shell_loop - A main loop of the shell
 * @datash: A pointer to the data shell structure
 *
 * Return: void
 */
void shell_loop(data_shell *datash)
{
	int loop, endOfInput;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&endOfInput);
		if (endOfInput != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			loop = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

