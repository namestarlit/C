#ifndef _ex19_h
#define _ex19_h

#include "object.h"

/**
 * struct Monster - object monster
 * @proto: object prototype
 * @hit_points: monster hit points
 */
struct Monster
{
	object proto;
	int hit_points;
};

typedef struct Monster Monster;

int Monster_attack(void *self, int damage);
int Monster_init(void *self);

/**
 * struct Room - Room object
 * @proto: object prototype
 * @bad_guy: Monster object
 * @north: north direction
 * @south: south direction
 * @est: est direction
 * @west: west direction
 */
struct Room
{
	object proto;

	Monster *bad_guy;

	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
};

typedef struct Room Room;

void *Room_move(void *self, Direction direction);
int Room_attack(void *self, int damage);
int Room_init(void *self);

/**
 * struct Map - Map object
 * @proto: object prototype
 * @start: Map initialization
 * @location: location
 */
struct Map
{
	object proto;
	Room *start;
	Room *location;
};

typedef struct Map Map;

void *Map_move(void *self, Direction direction);
int Map_attack(void *self, int damage);
int Map_init(void *self);

#endif /* _ex19_h */
