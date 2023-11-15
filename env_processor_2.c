#include "shell.h"

/**
 * copy_info - A function that copy the name and value
 * @name: The name string
 * @value: The value of string
 *
 * Return: A pointer to the new string
 */
char *copy_info(char *name, char *value)
{
	char *form;
	int length_name, length_value, length;

	length_name = _strlen(name);
	length_value = _strlen(value);
	length = length_name + length_value + 2;
	form = malloc(sizeof(char) * (length));
	_strcpy(form, name);
	_strcat(form, "=");
	_strcat(form, value);
	_strcat(form, "\0");

	return (form);
}

/**
 * set_env - A function that set the value of an environment variable
 *
 * @name: The name of the environment variable
 * @value: The value of set
 * @datash: Pointer to the data shell struct
 * Return: 1
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int n;
	char *cur_var, *ext_var;

	for (n = 0; datash->_environ[n]; n++)
	{
		cur_var = _strdup(datash->_environ[n]);
		ext_var = _strtok(cur_var, "=");
		if (_strcmp(ext_var, name) == 0)
		{
			free(datash->_environ[n]);
			datash->_environ[n] = copy_info(ext_var, value);
			free(cur_var);
			return;
		}
		free(cur_var);
	}

	datash->_environ = _reallocdp(datash->_environ, n, sizeof(char *) * (n + 2));
	datash->_environ[n] = copy_info(name, value);
	datash->_environ[n + 1] = NULL;
}

/**
 * _setenv - A function that set the value of an environment variable
 * @datash: A pointer to the data shell struct
 *
 * Return: 1
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv - A unset an environment variable
 *
 * @datash: A pointer to the data shell struct
 *
 * Return: 1
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int n, m, r;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	r = -1;
	for (n = 0; datash->_environ[n]; n++)
	{
		var_env = _strdup(datash->_environ[n]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			r = n;
		}
		free(var_env);
	}
	if (r == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (n));
	for (n = m = 0; datash->_environ[n]; n++)
	{
		if (n != r)
		{
			realloc_environ[n] = datash->_environ[n];
			m++;
		}
	}
	realloc_environ[m] = NULL;
	free(datash->_environ[r]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
