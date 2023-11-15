#include "shell.h"

/**
 * cd_shell - A function that change directory to the target directory
 * @datash: A pointer to the data shell struct
* Return: 1
 */
int cd_shell(data_shell *datash)
{
	char *targetDir;
	int isHome, isTildeHome, isDoubleDash;

	targetDir = datash->args[1];

	if (targetDir != NULL)
	{
		isHome = _strcmp("$HOME", targetDir);
		isTildeHome = _strcmp("~", targetDir);
		isDoubleDash = _strcmp("--", targetDir);
	}

	if (targetDir == NULL || !isHome || !isTildeHome || !isDoubleDash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", targetDir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", targetDir) == 0 || _strcmp("..", targetDir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}

