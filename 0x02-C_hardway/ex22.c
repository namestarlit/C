#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;
static int THE_AGE = 37;

/**
 * get_age - gets the age
 *
 * Return: The age
 */
int get_age(void)
{
	return (THE_AGE);
}

/**
 * set_age - sets the age
 * @age: age parameter
 */
void set_age(int age)
{
	THE_AGE = age;
}

/**
 * update_ratio - updates the ratio
 * @new_ratio: new ratio parameter
 *
 * Return: old ratio
 */
double update_ratio(double new_ratio)
{
	static double ratio = 1.0;
	double old_ratio = ratio;

	ratio = new_ratio;

	return (old_ratio);
}

/**
 * print_size - prints the value of THE_SIZE variable
 */
void print_size(void)
{
	log_info("I think the size is: %d", THE_SIZE);
}
