#include "shell.h"
#include <stdio.h>
#include <signal.h>

void get_sigint(int sig)
{
	printf("Received SIGINT signal: %d\n", sig);
}
