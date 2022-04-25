#ifndef VEC2
#define VEC2

#include <math.h>
#include <ncurses.h>
#include <stdlib.h>

#include "tiles.h"

typedef struct VEC2_
{
    int x;
    int y;
} Vec2;

int add(Vec2 v0, Vec2 v1);
int vec2equal(Vec2 v0, Vec2 v1);
void line_to_buf(Vec2 *buf, int *curr_len, Vec2 v0, Vec2 v1);

#endif