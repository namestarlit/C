#include <stdio.h>

/**
 * main - all operators in c
 *
 * Return: 0 (success)
 */
int main(void)
{
	int x = 10, y = 20, z;

	/* *(binary) multiply */
	z = x * y;
	printf("%d\n", z);

	/* / divide */
	z = x / y;
	printf("%d\n", z);

	/* +(binary) addition */
	z = x + y;
	printf("%d\n", z);
	
	/* +(unary) positive number */
	z = +x;
	printf("%d\n", z);

	/* ++(postfix) read, then increment */
	z = x++;
	printf("%d\n", z);

	/* ++(prefix) increment, then read */
	z = ++x;
	printf("%d\n", z);

	/* --(postfix) read, then decrement */
	z = y--;
	printf("%d\n", z);

	/* --(prefix) decrement, then read */
	z = --y;
	printf("%d\n", z);

	/* -(binary) subtract */
	z = y - x;
	printf("%d\n", z);

	/* -(unary) negative number */
	z = -y;
	printf("%d\n", z);

	return (0);
}
