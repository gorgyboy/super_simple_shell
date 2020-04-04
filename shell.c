#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - A super simple shell
 *
 * Return: EXIT_SUCCESS oon success, EXIT_FAILURE on failure
 */
int main()
{
	char *lineptr = NULL;
	char *token;
	size_t n = 0;
	size_t i;
	pid_t child_pid;
	int status;

	do
	{
		printf("$ ");
		if (getline(&lineptr, &n, stdin) == -1)
		{
			printf("Error getting the line\n");
			break;
		}
		else
		{
			printf("%s", lineptr);
			token = strtok(lineptr, " \n");
			for (i = 0; token != NULL; i++)
			{
				printf("Token %lu: %s\n", i, token);
				token = strtok(NULL, " \n");
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
		}
	} while (strcmp(lineptr, "exit\n") != 0);
	free(lineptr);
	return (EXIT_SUCCESS);
}
