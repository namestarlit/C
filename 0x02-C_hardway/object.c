#include "object.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * object_destroy - frees object memory
 * @self: void parameter
 */
void object_destroy(void *self)
{
	object *obj = self;

	if (obj)
	{
		if (obj->description)
			free(obj->description);
		free(obj);
	}
}

/**
 * object_describe - prints object description
 * @self: void parameter
 */
void object_describe(void *self)
{
	object *obj = self;

	printf("%s.\n", obj->description);
}

/**
 * object_init - initializes object
 * @self: void parameter
 *
 * Return: 1
 */
int object_init(void *self)
{
	/* do nothing really */
	return (1);
}

/**
 * object_move - move function for game for game navigation
 * @self: void parameter
 * @direction: direction
 *
 * Return: NULL
 */
void *object_move(void *self, Direction direction)
{
	printf("You can't go that direction.\n");
	return (NULL);
}

/**
 * object_attack - object attack
 * @self: void parameter
 * @damage: damage inflicted count
 *
 * Return: 0 (success)
 */
int object_attack(void *self, int damage)
{
	printf("You can't attack that.\n");
	return (0);
}

/**
 * object_new - creates new object
 * @size: size of object
 * @proto: object prototype
 * @description: object description
 */
void *object_new(size_t size, object proto, char *description)
{
	/* set up the default functions in case they aren't set */
	if (!proto.init)
		proto.init = object_init;
	if (!proto.describe)
		proto.describe = object_describe;
	if (!proto.destroy)
		proto.destroy = object_destroy;
	if (!proto.attack)
		proto.attack = object_attack;
	if (!proto.move)
		proto.move = object_move;

	/**
 	* This seems weird but we can make a struct of one size then,
 	* point a different pointer at it to "cast" it
 	*/
	object *el = calloc(1, size);
	*el = proto;

	/* copy the description over */
	el->description = strdup(description);

	/* Initialize it with whatever init we were given */
	if (!el->init(el))
	{
		/* looks like it didn't iniatialize properly */
		el->destroy(el);
		return (NULL);
	}
	else
	{
		/* all done, we made an object of any type */
		return (el);
	}
}
