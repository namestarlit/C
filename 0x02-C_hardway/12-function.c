#include <stdio.h>
#include <ctype.h>
#include "function.h"

int can_print_it(char ch);
void print_letters(char arg[]);

/**
 * void print_arguments - prints arguments
 * @argc: argument count
 * @argv: argument vector
 */
void print_arguments (int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i ++)
		print_letters(argv[i]);
}

/**
 * print_letters - print letters
 * @arg: input string
 */
void print_letters(char arg[])
{
	int i;

	for (i = 0; arg[i] != '\0'; i++)
	{
		char ch = arg[i];

		if (can_print_it(ch))
			printf("'%c' == %d ", ch, ch);
	}
	printf("\n");
}

/**
 * can_print_it - checks if a character
 * is alphabetic or blank
 * @ch: input char
 *
 * Return: 1 (true), 0 (false)
 */
int can_print_it(char ch)
{
	return (isalpha(ch) || isblank(ch));
}

/**
 * main - prints argumetns
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	print_arguments(argc, argv);

	return (0);
}
