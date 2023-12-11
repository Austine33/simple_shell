/**
 * main - runs my shell
 * 
 * Return: Always 0 on success or 1 on error
 */
#include "main.h"
int main(void)
{
	int loop = 1;
	char *input_string;
	char **tokenised;
	char **command;
	while (loop)
	{
		printf("($) ");
		input_string = getcmd();
		tokenised = tokenise(input_string);
		command = path(tokenised);
		if (command[0] != NULL)
		{
			execute_args(command);
		}
		else
		{
			printf("command not found");
			sleep(1);
		}
	}
	return (0);
}
