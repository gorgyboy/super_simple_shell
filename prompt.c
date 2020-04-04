#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Program to learn how getline works
 *
 * Return: Always EXIT_SUCCESS
 */
int main (void)
{
	size_t n = 0;
	char *lineptr = NULL;

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
		}
	} while (strcmp(lineptr, "exit\n") != 0);
	free(lineptr);
	return (EXIT_SUCCESS);
}
