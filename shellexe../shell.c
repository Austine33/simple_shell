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
	/*char **command;*/
	int found = 0;
	while (loop)
	{
		printf("($) ");
		input_string = getcmd();
		tokenised = tokenise(input_string);
		/*command = path(tokenised);*/
		found = cmd_exists(&tokenised[0]);
		printf(".................1%s1........\n", tokenised[0]);
		if (found == 0)
		{
			execute_args(tokenised);
		}
		else
		{
			printf("command not found");
			sleep(1);
		}
	}
	return (0);
}
