#ifndef MAP
#define MAP

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "vec2.h"
#include "tiles.h"

int **init_map();
int do_sim_step(int **map);
int count_alive_neighbors(int **m, int x, int y);
int **cp_map(int **map);
int draw_map(int **map);

#endif