#ifndef PLAYER
#define PLAYER

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PLAYER_
{
    int x_pos;
    int y_pos;
    int health;
} Player;

#include "fov.h"
#include "tiles.h"

Player *player_setup();
int handle_input(int input, Player *user);
int player_move(int y, int x, Player *user);
int can_move(int new_y, int new_x, Player *user);

#endif