/**
 * getcmd - function to read the cli
 *
 * Return: the array of the string
 */
#include "main.h"
char *getcmd(void)
{
	size_t bytes = 0;
	char *line = NULL;

	if (getline(&line, &bytes, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
			free(line);
		}
		else
		{
			free(line);
			perror("error in reading from stdin");
		}
	}
	return (line);
}
