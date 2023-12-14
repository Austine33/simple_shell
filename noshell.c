#include "main.h"
/**
 * noshell - for non interactive mode
 *
 * Return: 0 on success
 */
int noshell(void)
{
	char *input_string;
	char **tokenised;
	char *cmd;
	int found = 0, dir_int = 0;

	input_string = getcmd();
	if (input_string[0] != '\n')
	{
		tokenised = tokenise(input_string);
		cmd = strdup(tokenised[0]);
		tokenised[0] = cmd;
		dir_int = dir(&cmd);
		if (dir_int != 0)
		{
			found = cmd_exists(&cmd);
		}
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
