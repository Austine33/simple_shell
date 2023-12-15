#include "main.h"
/**
 * execute_env - gives envrinoment string to standard output
 *
 * Returns: 0
 */

void execute_env(void)
{
int w = 3;
char **env = environ;
while (env[w]);
{
	write(STDOUT_FILENO,(const void *)env[w],strlen(env[w]));
	write(STDOUT_FILENO,"n\", 1);
}	w++;
}

