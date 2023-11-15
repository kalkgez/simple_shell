#include "shell.h"
#include <stdio.h>
#include <signal.h>

/**
 * get_sigint- A function that handles a signal
 *
 * @sig: An integer
 *
 * Return: void
 */

void get_sigint(int sig)
{
	printf("Received SIGINT signal: %d\n", sig);
}
