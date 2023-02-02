#include "ex19.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

/**
 * Monster_attack - attacks a bad_guy
 * @self: void parameter
 * @damage: damage inflicted to the bad_guy
 *
 * Return: 0 (bad_guy alive), 1 (bad_guy dead)
 */
int Monster_attack(void *self, int damage)
{
	Monster *monster = self;

	assert(damage != NULL);

	printf("You attack %s\n", monster->_(description));
	monster->hit_points -= damage;

	if (monster->hit_points > 0)
	{
		printf("It is still alive.\n");
		return (0);
	}
	else
	{
		printf("It is dead!\n");
		return (1);
	}
}

/**
 * Monster_init - initializes monster object
 * @self: void parameter
 *
 * Return: 1 (success)
 */
int Monster_init(void *self)
{
	Monster *monster = self;

	monster->hit_points = 10;

	return (1);
}

object MonsterProto = {
	.init = Monster_init,
	.attack = Monster_attack
};

/**
 * Room_move - movements in a Room object
 * @self: void parameter
 * @direction: direction in the room
 */
void *Room_move(void *self, Direction direction)
{
	Room *room = self;
	Room *next = NULL;

	if (direction == NORTH && room->north)
	{
		printf("You go north into: \n");
		next = room->north;
	}
	else if (direction == SOUTH && room->south)
	{
		printf("You go south into: \n");
		next = room->south;
	}
	else if (direction == EAST && room->east)
	{
		printf("You go east into: \n");
		next = room->east;
	}
	else if (direction == WEST && room->west)
	{
		printf("You go west into: \n");
		next = room->west;
	}
	else
	{
		printf("You can't go that direction");
		next = NULL;
	}

	if (next)
	{
		next->_(describe)(next);
	}
	return (next);
}

/**
 * Room_attack - attack in the Room object
 * @self: void parameter
 * @damage: damage inflicted to bad_guy
 *
 * Return: 1 (attack), 0 (missed attack)
 */
int Room_attack(void *self, int damage)
{
	Room *room = self;
	Monster *monster = room->bad_guy;

	if (monster)
	{
		monster->_(attack)(monster, damage);
		return (1);
	}
	else
	{
		printf("You frail in the air at nothing. Idiot\n");
		return (0);
	}
}

object RoomProto = {
	.move = Room_move,
	.attack = Room_attack
};

/**
 * Map_move - movements in the Map object
 * @self: void parameter
 * @direction: direction in the map object
 *
 * Return: next
 */
void *Map_move(void *self, Direction direction)
{
	Map *map = self;
	Room *location = map->location;
	Room *next = NULL;

	next = location->_(move)(location, direction); /* _(move) = proto.move */

	if (next)
		map->location = next;
	return (next);
}

/**
 * Map_attack - attack in map object
 * @self: void parameter
 * @damage: damage inflicted
 *
 * Return: attack location and damage
 */
int Map_attack(void *self, int damage)
{
	Map *map = self;
	Room *location = map->location;

	return (location->_(attack)(location, damage));
}

/**
 * Map_init - Map object initialization
 * @self: void parameter
 *
 * Return: 1 (success)
 */
int Map_init(void *self)
{
	Map *map = self;

	/* make some rooms for a small map */
	Room *hall = NEW(Room, "The great Hall");
	Room *throne = NEW(Room, "The throne room");
	Room *arena = NEW(Room, "The areana with the Minotaur");
	Room *kitchen = NEW(Room, "Kitchen, you have the knife now");

	/* put the bad_guy in the arena */
	arena->bad_guy = NEW(Monster, "The evil monotaur");

	/* set up the map rooms */
	hall->north = throne;

	throne->west = arena;
	throne->east = kitchen;
	throne->south = hall;

	arena->east = throne;
	kitchen->west = throne;

	/* start the map and the character off in the hall */
	map->start = hall;
	map->location = hall;

	return (1);
}

object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

/**
 * process_input - processes input for the game
 * @game: game input
 *
 * Return: 1 (success)
 */
int process_input(Map *game)
{
	printf("\n> ");
	char ch = getchar();

	getchar(); /* hit ENTER */

	int damage = rand() % 4;

	switch (ch)
	{
		case -1:
			printf("Giving up? You suck.\n");
			return (0);
		case 'n':
			game->_(move)(game, NORTH);
			break;
		case 's':
			game->_(move)(game, SOUTH);
			break;
		case 'e':
			game->_(move)(game, EAST);
			break;
		case 'w':
			game->_(move)(game, WEST);
			break;
		case 'a':
			game->_(attack)(game, damage);
			break;
		case 'l':
			printf("You can go: \n");

			if (game->location->north)
				printf("NORTH\n");
			if (game->location->south)
				printf("SOUTH\n");
			if (game->location->east)
				printf("EAST\n");
			if (game->location->west)
				printf("WEST\n");
			break;
		default:
			printf("What?: %d\n", ch);
	}
	return (1);
}

/**
 * main - game program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	/* simple way to set up the randomness */
	srand(time(NULL));

	/* make our map to work with */
	Map *game = NEW(Map, "The Hall of the Minotaur");

	printf("You enter the ");
	game->location->_(describe)(game->location);

	while (process_input(game))
	{
	}
	return (0);
}
