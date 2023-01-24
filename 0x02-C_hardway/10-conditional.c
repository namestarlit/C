#include <stdio.h>

/**
 * main - if, else-if, else statements
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int i =0;

	if(argc == 1)
	{
		puts("You only have one argument");
	}
	else if (argc > 1 && argc < 4)
	{
		puts("Here is your arguments");

		for (i = 0; i < argc; i++)
		{
			printf("%s ", argv[i]);
		}
		putchar('\n');
	}
	else
	{
		puts("You have too many arguments. You suck!");
	}

	return (0);
}
