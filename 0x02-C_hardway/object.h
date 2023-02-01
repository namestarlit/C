#ifndef _object_h
#define _object_h

#include <stddef.h>

/**
 * typedef enum - contains directions
 * used for navigation in the game ex19.c
 */
typedef enum
{
	NORTH, SOUTH, EAST, WEST
} Direction;

/**
 * typedef struct - objects prototype pointer functions
 * @description: game description
 * @init: initialization
 * @describe: description
 * @destroy: frees memory
 * @move: movements in the game
 * @direction: movement direction
 * @attack: function pointer to attack
 */
typedef struct
{
	char *description;
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*move)(void *self, Direction direction);
	int (*attack)(void *self, int damage);
} object;

int object_init(void *self);
void object_destroy(void *self);
void object_describe(void *self);
void *object_move(void *self, Direction direction);
int object_attack(void *self, int damage);
void *object_new(size_t size, object proto, char *description);

#define NEW(T, N) object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N

#endif /* _object_h */
