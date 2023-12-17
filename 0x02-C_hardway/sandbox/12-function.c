#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print_nu(char arg[]);

/**
 * print_args - prints arguments
 * @argc: argument count
 * @argv: argument vector
 */
void print_args(int argc, char *argv[])
{
	int i;
	
	for (i = 0; i < argc; i++)
	{
		print_nu(argv[i]);
	}
}

/**
 * print_nu - prints numbers
 * @arg: string 
 */
void print_nu(char arg[])
{
	int i, len;

	len = strlen(arg);

	for (i = 0; i < len; i++)
	{
		if (isdigit)
		{
			printf(" %5d == %c (ASCII)\n", arg[i], arg[i]);
		}
	}
	putchar('\n');
}

/**
 * main - prints number arguments
 * @argc: argument count
 * @argv: argument variable
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	print_args(argc, argv);

	return (0);
}
