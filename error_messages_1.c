#include "shell.h"

/**
 * strcat_cd - A function that concatenate the error message
 * @datash: Pointer to the data shell struct
 * @msg: The message to append
 * @error: The error string to build
 * @ver_str: The version string
 * Return: A pointer to the concatenated error string
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - A function that generate the error message
 * @datash: A pointer to the data shell struct
 * Return: A pointer to the generated error message
 */The error message string
char *error_get_cd(data_shell *datash)
{
	int length, length_id;
	char *error, *versionString, *statusMessage;

	versionString = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		statusMessage = ": Illegal option ";
		length_id = 2;
	}
	else
	{
		statusMessage = ": can't cd to ";
		length_id = _strlen(datash->args[1]);
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	length += _strlen(versionString) + _strlen(statusMessage) + length_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(versionString);
		return (NULL);
	}

	error = strcat_cd(datash, statusMessage, error, versionString);

	free(versionString);

	return (error);
}

/**
 * error_not_found - A function that generate the error message for cd command
 * @datash: A pointer to the data shell struct
 * Return: The error message string
 */
char *error_not_found(data_shell *datash)
{
	int length;
	char *error;
	char *versionString;

	versionString = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(versionString);
	length += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(versionString);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, versionString);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(versionString);
	return (error);
}

/**
 * error_exit_shell - A function that generate the error message
 * @datash: A pointer to the data shell struct
 *
 * Return: The error message string
 */
char *error_exit_shell(data_shell *datash)
{
	int length;
	char *error;
	char *versionString;

	versionString = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(versionString);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(versionString);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, versionString);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(versionString);

	return (error);
}
