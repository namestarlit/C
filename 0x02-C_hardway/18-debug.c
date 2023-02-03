#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * test_debug - test debug macro
 * from dbg.h
 */
void test_debug()
{
	/* notice you don't need the \n */
	debug("I have Brown Hair");

	/* passing in arguments like printf */
	debug("I am %d years old.", 37);
}

/**
 * test_log_err - test log_err macro
 * from dbg.h
 */
void test_log_err()
{
	log_err("I believe everything is broken");
	log_err("There are %d problems in %s.", 0, "space");
}

/**
 * test_log_warn - test log_warn macro
 * from dbg.h
 */
void test_log_warn()
{
	log_warn("You can safely ignore this.");
	log_warn("Maybe consider looking at: %s.", "/etc/passwd");
}

/**
 * test_log_info - test log_info macro
 * from dbg.h
 */
void test_log_info()
{
	log_info("Well, I did something mundane.");
	log_info("It happened %f times today.", 1.3f);
}

/**
 * test_check - test check macro
 * from dbg.h
 * @file_name: file name parameter
 *
 * Return: 0 (success), -1 (error)
 */
int test_check(char *file_name)
{
	FILE *input = NULL;
	char *block = NULL;

	block = (char *)malloc(100);
	check_mem(block); /* should work */

	input = fopen(file_name, "r");
	check(input, "Failed to open %s.", file_name);
	free(block);
	fclose(input);

	return (0);

error:
	if (block)
		free(block);
	if (input)
		fclose(input);

	return (-1);
}

/**
 * test_sentinel
 * @code: switch case argument
 *
 * Return: 0 (success), -1 (error)
 */
int test_sentinel(int code)
{
	char *temp = (char *)malloc(100);
	check_mem(temp);

	switch(code)
	{
		case 1:
			log_info("It worked");
			break;
		default:
			sentinel("I shouldn't run.");
	}
	free(temp);

	return (0);

error:
	if (temp)
		free(temp);
	return (-1);
}

/**
 * test_check_mem - test check_mem macro
 * from dbg.h
 *
 * Return: 1 (success), -1 (error)
 */
int test_check_mem()
{
	char *test = NULL;
	check_mem(test);
	free(test);

	return (1);

error:
	return (-1);
}

/**
 * test_check_debug - test check_debug macro
 * from dbg.h
 *
 * Return: 0 (success), -1 (error)
 */
int test_check_debug()
{
	int i = 0;

	check_debug(i != 0,"Oops! I was 0");
	return (0);

error:
	return (-1);
}

/**
 * main - testing dbg.h macros
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	check(argc == 2, "Need an argument");

	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();

	/**
	 * The way to read these lines is
	 * "check that A is true, and if not
	 * say M and jump out."
	 */
	check(test_check("18-debug.c") == 0, "failed with 18-debug.c");
	check(test_check(argv[1]) == -1, "failed with argv.");
	check(test_sentinel(1) == 0, "test_sentinel failed.");
	check(test_sentinel(100) == -1, "test_sentinel failed.");
	check(test_check_mem() == -1, "test_check_me failed.");
	check(test_check_debug() == -1, "test_check_debug failed");

	return (0);

error:
	return (1);
}
