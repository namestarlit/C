#include <stdio.h>

/**
 * Define constants to use
 * instead of variables
 *
 * symbolic constants
 * LOWER - lower limit of table
 * UPPER - upper limit
 * STEP - step size
 */

#define LOWER 0
#define UPPER 300
#define STEP 20

/**
 * main - prints Fahrenheit-Celsius Table
 *
 * Return: always 0 (success)
 */

int main(void)
{
	int fahr;

	printf("Fahrheit-Celsius Table\n");

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	return (0);
}
