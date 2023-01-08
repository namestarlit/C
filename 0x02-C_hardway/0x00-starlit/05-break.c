#include <stdio.h>

/**
 * main - breaking code
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	char name[4] = {'a', 'b', 'c', 'd', 'e'};

	/* when I print elements of name, 'e' is left out*/
	printf("name: %s\n", name);
	printf("name each: %c %c %c %c %c\n", name[0], name[1], name[2], name[3], name[4]);

	char next[3];

	next[0] = 'A';
	next[1] = 'B';
	next[2] = 'C';
	next[3] = 'D';
	next[4] = 'E';

	printf("next: %s\n", next);

	return (0);
}
