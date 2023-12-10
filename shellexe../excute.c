#include "main.h"
/**
 * execute_args - executes the command
 * 
 * tokens: an array of stings
 *
 * Return: 0 on success
 */
extern char **environ;

int execute_args(char **tokens)
{
	pid_t child;
	int stat;

	child = fork();
	if (child == -1)
	{
		perror("error in creating process");
		exit(EXIT_FAILURE);
		return (1);
	}
	if (child == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror("error in execution");
			exit(EXIT_FAILURE);
			return (1);
		}
	}
	else
	{
		wait(&stat);
		sleep(2);
	}
	return (0);
}
