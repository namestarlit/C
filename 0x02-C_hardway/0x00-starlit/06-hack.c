#include <stdio.h>

/**
 * main - hacking chars as ints using union
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	union hack {
		char name[4];
		int num;
	};

	union hack h;

	h.num = 1234; /* sets the integer value */

	printf("%d\n", h.num);

	h.name[0] = 'a';
	h.name[1] = 'b';
	h.name[2] = 'c';
	h.name[3] = 'd';

	printf("%s\n", h.name);

	return (0);
}
