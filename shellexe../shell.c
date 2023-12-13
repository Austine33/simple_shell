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
	char *cmd;
	
	/*char **command;*/
	int found = 0;
	while (loop)
	{
		printf("($) ");
		input_string = getcmd();
		tokenised = tokenise(input_string);
		cmd = malloc(200 * sizeof(char));
		if (cmd == NULL)
		{
			printf("error in allocating memory");
			exit(EXIT_FAILURE);
		}
		strcpy(cmd, tokenised[0]);
		tokenised[0] = cmd;
		/*command = path(tokenised);*/:wq
		found = cmd_exists(&cmd);
		printf(".................1%s1........\n", tokenised[0]);
		if (found == 0)
		{
			execute_args(tokenised);
			free(cmd);
		}
		else
		{
			printf("command not found");
			free(cmd);
			sleep(1);
		}
	}
	return (0);
}
