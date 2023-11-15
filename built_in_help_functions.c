#include "shell.h"

/**
 * aux_help_env - A function that displays help information for the env command
 * Return: void
 */
void aux_help_env(void)
{
	char *commandHelp = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));

}
/**
 * aux_help_setenv - A function that displays help
 * information for the setenv command
 * Return: void
 */
void aux_help_setenv(void)
{

	char *commandHelp = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "int replace)\n\t";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
}
/**
 * aux_help_unsetenv -  A function that displays help
 * information for the unsetenv command
 * Return: void
 */
void aux_help_unsetenv(void)
{
	char *commandHelp = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
}


/**
 * aux_help_general -  A function that displays help information
 * Return: void
 */
void aux_help_general(void)
{
	char *commandHelp = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "These commands are defined internally.Type 'help'";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "Type 'help name' to find out about the function 'name'.\n\n";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = " alias: alias [name=['string']]\ncd: cd [-L|[-P [-e]] [-@]]";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "[dir]\nexit: exit [n]\n env: env option name=value command ";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "[args]]\n  setenv: setenv [variable] [value]\nunsetenv: ";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "unsetenv [variable]\n";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
}
/**
 * aux_help_exit - A function that displays help
 * information  for the exit command
 * Return: void
 */
void aux_help_exit(void)
{
	char *commandHelp = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
}
