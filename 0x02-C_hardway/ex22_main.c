#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Zed A. Shaw";

/**
 * scope_demo - demonstrates scope of variables
 * @count: count parameter
 */
void scope_demo(int count)
{
	log_info("count is: %d", count);

	if (count > 10)
	{
		int count = 100; /* BAD! BUGS! */

		log_info("count in this scope is: %d", count);
	}

	log_info("count is at exit: %d", count);

	count = 3000;

	log_info("count after assign: %d", count);
}

/**
 * main - demonstrates scope of variables
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	/* test out THE_AGE accessors */
	log_info("My name: %s, age %d", MY_NAME, get_age());

	set_age(100);

	log_info("My age is now: %d", get_age());

	/* test out THE_SIZE extern */
	log_info("THE SIZE is now: %d", THE_SIZE);
	print_size();

	/* test the update_ratio function scope */
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(20.0));
	log_info("Ratio once more: %f", update_ratio(300.0));

	/* test the scope_demo function */
	int count = 4;

	scope_demo(count);
	/* this won't work at all */
	scope_demo(count * 20);

	log_info("count after calling scope demo: %d", count);

	return (0);
}
