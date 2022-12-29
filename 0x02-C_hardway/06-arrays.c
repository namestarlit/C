#include <stdio.h>

/**
 * main - arrays and sizeof() function
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Zed";
	char full_name[] = {
	'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'
	};

	printf("The size of an int: %lu\n", sizeof(int));
	printf("The size of areas (int[]): %lu\n", sizeof(areas));
	printf("The number of ints in areas: %lu\n", sizeof(areas) / sizeof(int));
	printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);
	printf("The size of a char: %lu\n", sizeof(char));
	printf("The size of name (char[]): %lu\n", sizeof(name));
	printf("The number of chars: %lu\n", sizeof(name) / sizeof(char));
	printf("The size of full name: %lu\n", sizeof(full_name));
	printf("The number of chars: %lu\n", sizeof(full_name) / sizeof(char));

	return (0);
}
