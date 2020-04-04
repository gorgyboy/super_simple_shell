#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - Program to learn how fork, wait and execve work
 * @ac: Number of args
 * @av: Args passed to the program
 *
 * Return: EXIT_SUCCESS oon success, EXIT_FAILURE on failure
 */
int main(int ac, char *av[])
{
	pid_t child_pid;
	int status;
	size_t i;

	if (ac != 4)
		return (EXIT_FAILURE);

	printf("\nPPID: %u\n", getppid());
	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			printf("Error, could not fork.\n");
			return (EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			printf("PID-0%lu: %u\n\n", i, getpid());
			if (execve(av[1], av, NULL) == -1)
			{
				printf("Error, could not execute.\n");
				return (EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			printf("\nPPID: %u\n", getppid());
		}
	}
	return (EXIT_SUCCESS);
}
