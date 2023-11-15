#include "shell.h"

/**
 * aux_help - A function that displays help information for the help command
 * Return: void
 */
void aux_help(void)
{
	char *commandHelp = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
}
/**
 * aux_help_alias - A function
 * that displays help function for the alias command
 * Return: void
 */
void aux_help_alias(void)
{
	char *commandHelp = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
}
/**
 * aux_help_cd - A function that displays help information for the cd command
 * Return:
 **/
void aux_help_cd(void)
{
	char *commandHelp = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
	commandHelp = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, commandHelp, _strlen(commandHelp));
}

