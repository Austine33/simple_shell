#include "main.h"
/**
 * main - runs the shell in both modes
 *
 * Return: 0 on success
 */
int main(void)
{
	if (isatty(0))
	{
		shell();
	}
	else
	{
		noshell();
	}
	return (0);
}
