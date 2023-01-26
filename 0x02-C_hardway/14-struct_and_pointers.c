#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * struct person - a structure of person details
 * @name: person name
 * @age: person age
 * @height: person height
 * @weight: person weight
 */
struct person{
	char *name;
	int age;
	int height;
	int weight;
};

/**
 * person_create - function to register new person
 * @name: person name
 * @age: person age
 * @height: person height
 * @weight: person weight
 *
 * Return: person details
 */
struct person *person_create(char *name, int age, int height, int weight)
{
	struct person *who; /* pointer to a structre person */

	/* allocate memory for struct person */
	who = malloc(sizeof(struct person));

	assert (who != NULL); /* assert malloc does not return NULL */

	who->name = strdup(name); /* allocates memory and duplicates a string */
	who->age = age;
	who->height = height;
	who->weight = weight;

	return (who);
}

/**
 * person_destroy - frees memory allocated for string name and struct person
 * @who: pointer to struct person
 */
void person_destroy(struct person *who)
{
	assert (who != NULL);

	free(who->name); /* frees allocated memory for string literal name */
	free(who); /* frees a whole structure memory */
}

void person_print(struct person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

/**
 * main - creates a new person details
 * @argc: argument count
 * @argv: argument vector
 *
 * Description: __attribute__ ((unused))
 * suppresses unused variable warning
 *
 * Return: 0 (success)
 */
int main(int __attribute__ ((unused))argc, char __attribute__ ((unused))*argv[])
{
	/* make two people structures */
	struct person *joe = person_create("Joe Alex", 32, 64, 140);

	struct person *frank = person_create("Frank Blank", 20, 72, 180);

	/* print them out and where they are in memory */
	printf("%s is at memory location: %p\n", joe->name, joe);
	person_print(joe);
	putchar('\n');

	printf("%s is at memory location: %p\n", frank->name, frank);
	person_print(frank);
	putchar('\n');

	/* make everyone 20 years and print them again */
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	person_print(joe);
	putchar('\n');

	frank->age += 20;
	frank->weight += 20;
	person_print(frank);

	/* destroy them both so we clean up */
	person_destroy(joe);
	person_destroy(frank);

	return (0);
}
