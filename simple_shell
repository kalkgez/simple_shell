#include "shell.h"

/**
 * get_error - A function that handle and display error messages
 * @datash: A pointer to the data shell struct
 * @eval: The evaluation code
 * Return: Te evaluation code
 */
int get_error(data_shell *datash, int eval)
{
	char *errorMessage;

	switch (eval)
	{
	case -1:
		errorMessage = error_env(datash);
		break;
	case 126:
		errorMessage = error_path_126(datash);
		break;
	case 127:
		errorMessage = error_not_found(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			errorMessage = error_exit_shell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			errorMessage = error_get_cd(datash);
		break;
	}

	if (errorMessage)
	{
		write(STDERR_FILENO, errorMessage, _strlen(errorMessage));
		free(errorMessage);
	}

	datash->status = eval;
	return (eval);
}

