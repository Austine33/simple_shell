#include "main.h"
/**
 *
 *
 *
 *
 */

char *find_path(char *cmd)
{
	char *paths = getenv("PATH");
	char *path;
	int dir_len = 0;
	int cmd_len = 0;
	char *new_cmd = NULL;
	/*char arr[100];*/
	struct stat st;

	if (cmd[0] == '/')
	{
		return (cmd);
	}
	else
	{
		path = strtok(paths, ":");
		while (path != NULL)
		{
			dir_len = strlen(path);
			cmd_len = strlen(cmd);
			if (new_cmd == NULL)
			{
				new_cmd = malloc(sizeof(char) * (dir_len + cmd_len + 2));
				if (new_cmd == NULL)
				{
					printf("error in memory allocation");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				new_cmd = realloc(new_cmd, (dir_len + cmd_len + 2));
				if (new_cmd == NULL)
				{
					printf("error in memory allocation");
					exit(EXIT_FAILURE);
				}
			}
			strcpy(new_cmd, path);
			strcat(new_cmd, "/");

			strcat(new_cmd, cmd);
			strcat(new_cmd, "\0");
			/*strcpy(arr, new_cmd);*/
			if (stat(new_cmd, &st) == 0)
			{
				/*printf("%s", arr);*/
				return (new_cmd);
			}
			else
			{
				path = strtok(NULL, ":");
				free(new_cmd);
			}
		}	
	}
	return (NULL);
}
