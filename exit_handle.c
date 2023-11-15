#include "shell.h"

/**
 * exit_shell - A function that exits the shell with a specified status code.
 *
 * @datash: A pointer to the data shell structure
 * Return: 0 if the exit shell function completes successfully
 */
int exit_shell(data_shell *datash)
{
	unsigned int status;
	int digit;
	int str_length;
	int large_num;

	if (datash->args[1] != NULL)
	{
		status = _atoi(datash->args[1]);
		digit = _isdigit(datash->args[1]);
		str_length = _strlen(datash->args[1]);
		large_num = status > (unsigned int)INT_MAX;
		if (!digit || str_length > 10 || large_num)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (status % 256);
	}
	return (0);
}

