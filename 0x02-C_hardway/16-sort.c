#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * die - kills a program at error
 * @message: error message
 */
void die(const char *message)
{
	if (errno)
		perror(message);
	else
		printf("ERROR: %s\n", message);

	exit(1);
}

/**
 * typedef compare_cb - defines a function pointer as a data type
 * @a: 1st argument
 * @b: 2nd argument
 *
 * Return: sorted order
 */
typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int i, j, tmp;

	int *target = (int *)malloc(sizeof(int) * count);
	if (!target)
		die("Memory Error");

	memcpy(target, numbers, sizeof(int) * count);

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - 1; j++)
		{
			if (cmp (target[j], target[j - 1]) > 0)
			{
				tmp = target[j + 1];
				target[j + 1] = target[j];
				target[j] = tmp;
			}
		}
	}

	return (target);
}

/**
 * sorted_order - sorts integers
 * @a: 1st parameter
 * @b: 2nd parameter
 */
int sorted_order(int a, int b)
{
	return (a - b);
}

/**
 * reverse_order - reverses order
 * @a: 1st parameter
 * @b: 2nd parameter
 *
 * Return: Reversed order
 */
int reverse_order(int a, int b)
{
	return (b - a);
}

/**
 * strange_order - handles strange orders
 * @a: 1st argument
 * @b: 2nd argument
 *
 * Return: sorted order
 */
int strange_order(int a, int b)
{
	if (a == 0 || b == 0)
		return (0);
	else
		return (a %b);
}

/**
 * test_sorting - tests by sorts and printing out all
 * @numbers: numbers array
 * @count: total number of array elements
 * @cmp: function pointer
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i;

	int *sorted = bubble_sort(numbers, count, cmp);
	if (!sorted)
		die("Failed to sort as required");

	for (i = 0; i < count; i++)
	{
		printf("%d ", sorted[i]);
	}
	putchar('\n');

	unsigned char *data = (unsigned char *)cmp;

	for (i = 0; i < 25; i++)
	{
		printf("%02x:", data[i]);
	}
	putchar('\n');

	free(sorted);
}

/**
 * main - sorting integers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
		die("USAGE: sort 4 3 1 5 6");

	int i;
	int count = argc - 1;
	char **inputs = argv + 1;

	int *numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		die("Memory Error");

	for (i = 0; i < count; i++)
	{
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers);

	return (0);
}
