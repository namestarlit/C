#include <stdio.h>

/**
 * main - array of strings and for loop
 * @argc: argument count
 * @argv: argument vector (array of strings)
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int i = 0;

	/* Go through each string in argv */
	/* Why skipping argv[0?] */
	for (i = 1; i < argc; i++)
	{
		printf("arg %d: %s\n", i, argv[i]);
	}

	/* Let's make our own array of strings */
	char *states[] = {
		"California", "Oregon",
		"Washington", NULL
	};
	int num_states = 4;

	putchar('\n');

	for (i = 0; i < num_states; i++)
	{
		printf("state %d: %s\n", i, states[i]);
	}

	return (0);
}
