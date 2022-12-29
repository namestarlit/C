#include <stdio.h>

/**
 * main - variables in different forms
 *
 * Return: 0 (seccess)
 */

int main(int argc, char *argv[])
{
	int nu = 20;
	char c = 'P';
	float f = 2.576e3f;
	double d = 2576.75e10;
	char space[] = " ";
	char fname[] = "Paul";
	char sname[] = "John";

	printf("Number: %d (%i).\n", nu, nu);
	printf("ASCII 20: %c.\n", nu);
	printf("Character: %c.\n", c);
	printf("ASCII %c: %d.\n", c, c);
	printf("Float: %f (%e).\n", f, f);
	printf("Shorter: %g.\n", f);
	printf("Double: %lf.\n", d);
	printf("Shorter: %g.\n", d);
	printf("My name is %s%s%s.\n", fname, space, sname);
	printf("Address of space: %p.\n", &space);
	printf("Adios!\n");

	return (0);
}
