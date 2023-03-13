#include <stdio.h>

/**
 * main - arrays and sizeof() function
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int areas[6];

	areas[0] = 100;
	areas[1] = 20;
	areas[2] = 170;
	areas[3] = 50;
	areas[4] = 34;

	char name[] = "No name!";
	char full_name[] = {
	'P', 'a', 'u', 'l', ' ', 'J', 'o', 'h', 'n', '\0'
	};

	printf("Size of areas[0]: %lu byte(s)\n", sizeof(areas[0]));
	printf("Size of areas[1]: %lu byte(s)\n", sizeof(areas[1]));
	printf("Size of areas[2]: %lu byte(s)\n", sizeof(areas[2]));
	printf("Size of areas[3]: %lu byte(s)\n", sizeof(areas[3]));
	printf("Size of areas[4]: %lu byte(s)\n", sizeof(areas[4]));
	printf("Size of areas[]: %lu byte(s)\n", sizeof(areas));
	printf("Number of characters in areas[]: %lu characters.\n", sizeof(areas) / sizeof(int));
	printf("Size of full_name[]: %lu byte(s)\n", sizeof(full_name));
	printf("My full names: %s\n", full_name);
	printf("Name: %s\n", name);
	printf("Hexing my full name's address : %p\n", &full_name);

	return (0);
}
