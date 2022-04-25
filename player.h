#ifndef PLAYER
#define PLAYER

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vec2.h"

typedef struct PLAYER_
{
    Vec2 pos;
    int health;
} Player;

#include "fov.h"
#include "tiles.h"

Player *player_setup(Vec2 start_pos);
int handle_input(int input, Player *user);
int player_move(Vec2 pos, Player *user);
int can_move(Vec2 pos, Player *user);

#endif