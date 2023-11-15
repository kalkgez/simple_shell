#include "shell.h"

/**
 * cd_dot - A function that change directory to the current directory
 * @datash: A pointer to the data shell struct
 * Return: void
 */
void cd_dot(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *currentPwd, *modifiedPwd;

	getcwd(pwd, sizeof(pwd));
	currentPwd = _strdup(pwd);
	set_env("OLDPWD", currentPwd, datash);
	dir = datash->args[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", currentPwd, datash);
		free(currentPwd);
		return;
	}
	if (_strcmp("/", currentPwd) == 0)
	{
		free(currentPwd);
		return;
	}
	modifiedPwd = currentPwd;
	rev_string(modifiedPwd);
	modifiedPwd = _strtok(modifiedPwd, "/");
	if (modifiedPwd != NULL)
	{
		modifiedPwd = _strtok(NULL, "\0");

		if (modifiedPwd != NULL)
			rev_string(modifiedPwd);
	}
	if (modifiedPwd != NULL)
	{
		chdir(modifiedPwd);
		set_env("PWD", modifiedPwd, datash);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", datash);
	}
	datash->status = 0;
	free(currentPwd);
}

/**
 * cd_to - A function that change a directory to a specified directory
 *
 * @datash: A pointer to the data shell
 * Return: void
 */
void cd_to(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *currentPwd, *specifiedDir;

	getcwd(pwd, sizeof(pwd));

	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
		get_error(datash, 2);
		return;
	}

	currentPwd = _strdup(pwd);
	set_env("OLDPWD", currentPwd, datash);

	specifiedDir = _strdup(dir);
	set_env("PWD", specifiedDir, datash);

	free(currentPwd);
	free(specifiedDir);

	datash->status = 0;

	chdir(dir);
}

/**
 * cd_previous - A function that change a directory to the previous directory
 *
 * @datash: A pointer to the data shell struct
 * Return: void
 */
void cd_previous(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *currentPwd, *previousPwd;

	getcwd(pwd, sizeof(pwd));
	currentPwd = _strdup(pwd);

	p_oldpwd = _getenv("OLDPWD", datash->_environ);

	if (p_oldpwd == NULL)
		previousPwd = currentPwd;
	else
		previousPwd = _strdup(p_oldpwd);

	set_env("OLDPWD", currentPwd, datash);

	if (chdir(previousPwd) == -1)
		set_env("PWD", currentPwd, datash);
	else
		set_env("PWD", previousPwd, datash);

	p_pwd = _getenv("PWD", datash->_environ);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(currentPwd);
	if (p_oldpwd)
		free(previousPwd);

	datash->status = 0;

	chdir(p_pwd);
}

/**
 * cd_to_home - A function that change directory to home directory
 *
 * @datash: A pointer to the data shell struct
 * Return: void
 */
void cd_to_home(data_shell *datash)
{
	char *p_pwd, *homeDir;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	homeDir = _getenv("HOME", datash->_environ);

	if (homeDir == NULL)
	{
		set_env("OLDPWD", p_pwd, datash);
		free(p_pwd);
		return;
	}

	if (chdir(homeDir) == -1)
	{
		get_error(datash, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, datash);
	set_env("PWD", homeDir, datash);
	free(p_pwd);
	datash->status = 0;
}
