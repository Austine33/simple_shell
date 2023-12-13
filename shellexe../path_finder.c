#include "main.h"
int cmd_exists(char **arr)
{
	struct stat st;
	char *paths = getenv("PATH");
	char *copy;
	char *path;
	char *temp = strdup(*arr);
	int dir = 0;
	int cmd = 0;
	char *array;
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
		dir = strlen(path);
		cmd = strlen(temp);
		array = malloc((dir + cmd + 2) * sizeof(char));
		strcpy(array, path);
		strcat(array, "/");
		strcat(array, temp);
		strcat(array, "\0");
		if (stat(array, &st) == 0)
		{
			strcpy(*arr, array);
			free(array);
			free(temp);
			free(copy);
			return (0);
		}
		else
		{
			path = strtok(NULL, ":");
		}
	}
	free(array);
	free(temp);
	free(copy);
	return (1);
}
