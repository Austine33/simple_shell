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
	int found = 0;

	while (loop)
	{
		printf("($) ");
		input_string = getcmd();
		tokenised = tokenise(input_string);
		cmd = strdup(tokenised[0]);
		tokenised[0] = cmd;
		/*command = path(tokenised);*/
		found = cmd_exists(&cmd);
		if (found == 0)
		{
			execute_args(tokenised);
			free(cmd);
		}
		else
		{
			printf("command not found\n");
			free(cmd);
			sleep(1);
		}
	}
	return (0);
}
