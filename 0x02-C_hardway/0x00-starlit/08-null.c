#include <stdio.h>

/**
 * main - illustrates NULL pointer
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	char *cities[] = {
		"Mwanza", "Dar es Salaam",
		"Arusha", NULL
	};
	int i, size = 4;

	for (i = 0; i < size; i++)
	{
		printf("%s\n", cities[i]);
	}

	return (0);
}
