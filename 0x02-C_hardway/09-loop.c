#include <stdio.h>

/**
 * main - illustrates while loop and array of strings
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	/* Go through each string in argv */
	int i = 0;

	while (i < argc)
	{
		printf("arg %d: %s\n", i, argv[i]);
		i++;
	}

	putchar('\n');

	/* Let's make our own array of strings */
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 4;

	i = 0;

	while (i < num_states)
	{
		printf("state %d: %s\n", i, states[i]);
		i++;
	}

	return (0);
}
