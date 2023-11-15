#include "shell.h"

/**
 * error_env - A function that generate the error message for environment
 * @datash: A pointer to the data shell struct
 * Return: The error message string
 */
char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *version_string;
	char *statusMessage;

	version_string = aux_itoa(datash->counter);
	statusMessage = ": Unable to add/remove from environment\n";
	length = _strlen(datash->av[0]) + _strlen(version_string);
	length += _strlen(datash->args[0]) + _strlen(statusMessage) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(version_string);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, version_string);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, statusMessage);
	_strcat(error, "\0");
	free(version_string);

	return (error);
}
/**
 * error_path_126 - A function that generate the error message for permissions
 * @datash: Pointer to the data shell struct
 *
 * Return: 
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *version_string;
	char *error;

	version_string = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(version_string);
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(version_string);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, version_string);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(version_string);
	return (error);
}
