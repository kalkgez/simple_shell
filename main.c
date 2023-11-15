#include "shell.h"
/**
 * free_data - A function that frees the memory allocated for the data shell
 * @datash: A pointer to the data shell struct
 * Return: void
 */
void free_data(data_shell *datash)
{
	unsigned int n;

	for (n = 0; datash->_environ[n]; n++)
	{
		free(datash->_environ[n]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - A function that initialises the data shell struct
 * @datash: A pointer to the data shell struct
 * @av: command line argumnet
 * Return: void
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int n;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (n = 0; environ[n]; n++)
		;

	datash->_environ = malloc(sizeof(char *) * (n + 1));

	for (n = 0; environ[i]; n++)
	{
		datash->_environ[i] = _strdup(environ[n]);
	}

	datash->_environ[n] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - A function that entry point of the program
 * @ac: A number of command line arguments
 * @av: An array of command line argumnet
 * Return: Exit status of the program
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
