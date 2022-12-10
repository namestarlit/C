#include <stdio.h>

/**
 * main - prints Celsius-Fahrenheit Table
 * celsius: for celsius = 0, 10, ..., 100
 *
 * Return: always 0 (success)
 */

int main(void)
{
	float celsius, fahr;
	float lower, upper, step;

	/**
	 * lower: lower limit temperature scale
	 * upper: upper limit
	 * step: step size
	 */

	lower = 0;
	upper = 100;
	step = 10;

	celsius = lower;

	printf("Celsius-Fahrenheit Table\n");

	while (celsius <= upper)
	{
		fahr = (9.0 / 5.0 * celsius) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return (0);
}
