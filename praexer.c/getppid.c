#include <stdio.h>
#include <unistd.h>

/**
 * main - ppid
 *
 * Return: Always 0.
 */
int main(void)
{
pid_t ausparent_pid;

ausparent_pid = getppid();
printf("%u\n", ausparent_pid);
return (0);
}
