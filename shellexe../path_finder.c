#include "main.h"
int cmd_exists(char **arr)
{
	struct stat st;
	char *paths = getenv("PATH");
	char *copy;
	char *path;
	char *temp = strdup(*arr);

	printf("%s\n", *arr);
	if (stat(*arr, &st) == 0)
	{
		return (0);
	}
	copy = strdup(paths);
	if (copy == NULL)
	{
		printf("error in allocation");
		exit(EXIT_FAILURE);
	}
	path = strtok(copy, ":");
	while (path != NULL)
	{
		strcpy(*arr, path);
		strcat(*arr, "/");
		strcat(*arr, temp);
		strcat(*arr, "\0");
		if (stat(*arr, &st) == 0)
		{
			free(temp);
			free(copy);
			return (0);
		}
		else
		{
			path = strtok(NULL, ":");
		}
	}
	free(temp);
	free(copy);
	return (1);
}
