#include "shell.h"

/**
 * exec_line - A function that executes a command line
 *
 * @datash: A pointer to the data shell struct
 * Return: An exit status of the execution
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}

