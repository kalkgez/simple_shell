#include "shell.h"

/**
 * cmp_env_name - A function that compare an environment
 * @nenv: The environment variable
 * @name: The given name to comapre
 *
 * Return: The number of characters
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int n;

	for (n = 0; nenv[n] != '='; n++)
	{
		if (nenv[n] != name[n])
		{
			return (0);
		}
	}

	return (n + 1);
}

/**
 * _getenv - A function that get the value of an environment
 * @name: The name of the environment variable
 * @_environ: The array of environment
 *
 * Return: A pointer to the value of the enviroment
 */
char *_getenv(const char *name, char **_environ)
{
	char *env_var;
	int n, mov;


	env_var = NULL;
	mov = 0;

	for (n = 0; _environ[n]; n++)
	{

		mov = cmp_env_name(_environ[n], name);
		if (mov)
		{
			env_var = _environ[n];
			break;
		}
	}

	return (env_var + mov);
}

/**
 * _env - A function that print the environment variable
 *
 * @datash: A pointer to the data shell struct
 * Return: 1
 */
int _env(data_shell *datash)
{
	int n, m;

	for (n = 0; datash->_environ[n]; n++)
	{

		for (m = 0; datash->_environ[n][m]; m++)
			;

		write(STDOUT_FILENO, datash->_environ[n], m);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}

