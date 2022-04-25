#ifndef FOV
#define FOV

#include <ncurses.h>

#include "player.h"
#include "vec2.h"

#define FOV_LEN_MAX 1000
#define TURN_IN_RAD 6.28319

int draw_fov(Player *user);
void reset_visible();
void populate_visible(Player *user);
void draw_visible(Player *user, int show_buf_len);

#endif