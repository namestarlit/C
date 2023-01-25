#include <stdio.h>

/**
 * main - working with pointers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int __attribute__ ((unused))argc, char __attribute__ ((unused))*argv[])
{
	/* create two arrays we care about */
	int ages[] = {23, 43, 12, 89, 12};
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	/* Safely get the size of ages */
	int count = sizeof(ages) / sizeof(int);
	
	int i;

	/* First way using indexing */
	for (i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}
	printf("___\n");

	/* Setup the pointers to the start of the arrays */
	int *cur_ages = ages;
	char **cur_names = names;

	/* Second way using pointers */
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old.\n", *(cur_names + i), *(cur_ages + i));
	}
	printf("___\n");

	/* Third way, pointers are just arrays */
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old ages.\n", cur_names[i], cur_ages[i]);
	}
	printf("___\n");

	/* Forth way with pointers in a stupid complex way */
	for (cur_names = names, cur_ages = ages; (cur_ages - ages) < count; cur_names++, cur_ages++)
	{
		printf("%s lived %d years so far.\n", *cur_names, *cur_ages);
	}
	putchar('\n');

	return (0);
}
