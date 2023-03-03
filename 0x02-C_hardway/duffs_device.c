#include <stdio.h>
#include <string.h>
#include "dbg.h"

/** THERE IS NO OUPUT FROM THIS PROGRAM, IT JUST RUNS AND EXITS **/

/**
 * normal_copy - copies an array to another array
 * @from: pointer to source array
 * @to: pointer to destination array
 *
 * Return: total copied characters (i);
 */
int normal_copy(char *from, char *to, int count)
{
	int i = 0;

	for (i = 0; i < count; i++)
	{
		to[i] = from[i];
	}

	return (i);
}

/**
 * duffs_device - copies an array to another array
 * in a weird evil way
 * @from: source array
 * @to: destination array
 *
 * Return: count (number of copied characters)
 */
int duffs_device(char *from, char *to, int count)
{
	{
		int n = (count + 7 ) / 8;

		switch (count % 8)
		{
			case 0: do {
					*to++ = *from++;

					case 7: *to++ = *from++;
					case 6: *to++ = *from++;
					case 5: *to++ = *from++;
					case 4: *to++ = *from++;
					case 3: *to++ = *from++;
					case 2: *to++ = *from++;
					case 1: *to++ = *from++;
				}while (--n > 0);
		}
	}
	return (count);
}

/**
 * zeds_device - modified version of duff's device
 * @from: pointer to source array
 * @to: pointer to destination array
 *
 * Return: count (number of copied characters)
 */
int zeds_device(char *from, char *to, int count)
{
	int n = (count + 7) / 8;

	switch (count % 8)
	{
		case 0:
		again: *to++ = *from++;

		case 7: *to++ = *from++;
		case 6: *to++ = *from++;
		case 5: *to++ = *from++;
		case 4: *to++ = *from++;
		case 3: *to++ = *from++;
		case 2: *to++ = *from++;
		case 1: *to++ = *from++;
			if (--n > 0) goto again;
	}
	return (count);
}

/**
 * vali_copy - checks for valid copying
 * @data: array of data characters
 * @count: number of copies
 * @expects: a character variable
 *
 * Return: 0 (success), 1 (failure)
 */
int valid_copy(char *data, int count, char expects)
{
	int i = 0;

	for (i = 0; i < count; i++)
	{
		if (data[i] != expects)
		{
			log_err("[%d] %c != %c", i, data[i], expects);
			return (0);
		}
	}
	return (1);
}

int main(int argc, char *argv[])
{
	char from[1000] = {'a'};
	char to[1000] = {'c'};

	int rc = 0;

	/* setup the from to have some stuff */
	memset(from, 'x', 1000);
	/*set it to a failure */
	memset(to, 'y', 1000);
	check(valid_copy(to, 1000, 'y'), "Not initialized right.");

	/* use normal copy to */
	rc = normal_copy(from, to, 1000);

	/* reset */
	memset(to, 'y', 1000);

	/* deff's version */
	rc = duffs_device(from, to, 1000);
	check(rc == 1000, "Duff's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Duff's device failed copy.");

	/* reset */
	memset(to, 'y', 1000);

	/* My version */
	rc = zeds_device(from, to, 1000);
	check(rc == 1000, "Zed's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Zed's device failed copy.");

	return (0);

error:
	return (1);
}
