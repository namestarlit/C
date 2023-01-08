#include <stdio.h>
#include <stdbool.h>

/**
 * main - trying to see how the while loop
 * will react from this
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	while (true)
	{
		puts("I will print this line forever");
		puts("Oops! they broke me!");
		break;
	}

	return (0);
}
