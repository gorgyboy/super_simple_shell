#include <stdio.h>
/**
 * main - Program to learn how ac and av work as arguments
 * @ac: Number of args
 * @av: Args passed to the program
 *
 * Return: Always 0
 */
int main (int ac, char **av)
{
	unsigned int idx;

	for (idx = 0; av[idx] != NULL; idx++)
		printf("%s\n", av[idx]);
	return (0);	
}
