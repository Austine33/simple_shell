#include "main.h"
/**
 * dir - looks if a directory exists
 * @dir: is the name of the command
 * Return: 0 on succes
 */
int dir(char **dir)
{
	struct stat st;

	if (stat(*dir, &st) == 0)
	{
		return (0);
	}
	else
	{
		return (2);
	}
}
