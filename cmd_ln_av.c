#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Program to learn how strtok works
 *
 * Return: On success EXIT_SUCCESS, on failure EXIT_FAILURE
 */
int main(void)
{
	char *token;
	char *lineptr = NULL;
	size_t n = 0;
	size_t i;

	printf("$ ");
	if (getline(&lineptr, &n, stdin) == -1)
	{
		free(lineptr);
		printf("Error getting the line\n");
		return (EXIT_FAILURE);
	}
	else
	{
		token = strtok(lineptr, " \n");
		for (i = 0; token != NULL; i++)
		{
			printf("Token %lu: %s\n", i, token);
			token = strtok(NULL, " \n");
		}
	}
	free(lineptr);
	return (EXIT_SUCCESS);
}
