#include "main.h"
/**
 * path - checks to see if a command is valid or not
 *
 * Return: a char** if the token is valid
 *
 * @token - a char**of the input command
 */

char **path(char **tokenised)
{
    int i = 0;
    char **null_ptr = NULL;
    int count = 1;
    char **new_token;
    int j = 0;
    struct stat st;
    char *paths = getenv("PATH");
    char *path;
    int dir_len = 0;
    int cmd_len = 0;
    char *new_cmd;
    char arr[20];
    char *cp_paths;
    /*char array[1][20];*/
    int op = 0;
    int x = 0;

    if (tokenised[0][0] == '/')
    {
        return (tokenised);
    }
    else
    {
	    cp_paths = strdup(paths);
	    while (tokenised[i] != NULL)
	    {
		    i += 1;
            count = count + 1;
        }
        count += 1;
        new_token = malloc(count * sizeof(char *));
        if (new_token == NULL)
        {
            printf("error in execution\n");
            exit(EXIT_FAILURE);
        }
        path = strtok(cp_paths, ":");
        while (path != NULL)
        {
            dir_len = strlen(path);
            cmd_len = strlen(tokenised[0]);
            new_cmd = malloc(sizeof(char) * (dir_len + cmd_len + 2));
            if (new_cmd == NULL)
            {
                printf("error in execution");
		free(cp_paths);
                exit(EXIT_FAILURE);
            }
            strcpy(new_cmd, path);
            strcat(new_cmd, "/");
            strcat(new_cmd, tokenised[0]);
            strcat(new_cmd, "\0");
            strcpy(arr, new_cmd);
            if (stat(new_cmd, &st) == 0)
            {
                new_token[j] = arr;
                /*array[0][j] = arr;*/
                j += 1;
                op = 1;
		free(cp_paths);
                break;
            }
            else
            {
                free(new_cmd);
                path = strtok(NULL, ":");
            }
        }
        if (op == 1)
        {
            while (tokenised[j] != NULL)
            {
                new_token[j] = tokenised[j];
                /*array[0][j] = tokenised[j];*/
                printf("\n%s", new_token[j]);
                j += 1;
            }
            printf("[");
            while (new_token[x] != NULL)
            {
                printf(" %s, ", new_token[x]);
                x += 1;
            }
            new_token[j] = NULL;
            /*array[0][j] = NULL;*/
            if (new_token[j] == NULL)
            {
                printf("NULL]\n");
            }
            free(new_cmd);
            return (new_token);
            /*return(array);*/
        }
	free(new_cmd);
        free(new_token);
        return (null_ptr);
    }
}
