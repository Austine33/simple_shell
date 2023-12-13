#include "main.h"
/**
 * tokenise - the function to tokenise the input from the commans
 *
 * @line: is the command form the cli
 *
 * Return: an array of  the tokenised strings
 */

char **tokenise(char *line)
{
	char **token;
	int i = 0;
	int j = 0;
	char *copy_of_line;
	char *tok;

	copy_of_line = strdup(line);
	tok = strtok(line, " \n");
	while (tok != NULL)
	{
		i += 1;
		tok = strtok(NULL, " \n");
	}
	token = malloc((i + 1) * sizeof(char *));
	if (token == NULL)
	{
		printf("error in allocation");
		exit(1);
	}
	tok = strtok(copy_of_line, " \n");
	while (tok != NULL)
	{
		token[j] = tok;
		j += 1;
		tok = strtok(NULL, " \n");
	}	
	token[i] = NULL;
	return (token);
}
