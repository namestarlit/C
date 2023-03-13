#include <stdio.h>

/**
 * main - commas in for loop
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int i, j;

	/**
	 * comma is used to separate multiple statements
	 * in the parts of a for-loop, you can use the comma
	 * inside the loop definition, between the initialization
	 * and condition
	 */
	for (i = 0, j = 10; i < j; i++, j--)
	{
		puts("This is some comma magic!");
	}

	return (0);
}
