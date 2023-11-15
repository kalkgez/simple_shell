#include "shell.h"

/**
 * get_builtin - A function that get the pointer for builtin
 * @cmd: command line
 * Return: A function pointer
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t own_builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int n;

	for (n = 0; own_builtin[n].name; n++)
	{
		if (_strcmp(own_builtin[n].name, cmd) == 0)
			break;
	}
	return (own_builtin[n].f);
}

