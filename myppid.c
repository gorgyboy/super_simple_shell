#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Program to learn how getpid and getppid works
 *
 * Return: Always 0
 */
int main (void)
{
	pid_t my_ppid, my_pid;

	my_pid = getpid();
	my_ppid = getppid();

	printf("PPID: %u, PID: %u\n", my_ppid, my_pid);

	return (0);
}
