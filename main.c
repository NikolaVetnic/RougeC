#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>

#include "map.h"
#include "player.h"

/* global variables */
Player *user;
int **map;
int curr_input;

/* function declarations */
int utf_init();

int screen_setup();
int map_setup();

int plot_line();

/* functions */
int main()
{
    utf_init();

    screen_setup();
    map_setup();

    Vec2 start_pos = {.x = 14, .y = 14};
    user = player_setup(start_pos);

    /* main game loop */
    while ((curr_input = getch()) != 'q')
    {
        handle_input(curr_input, user);
    }
    endwin();

    return 0;
}

int utf_init()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    return 0;
}

int screen_setup()
{
    initscr();
    noecho();
    refresh();

    return 0;
}

int map_setup()
{
    map = init_map();
    draw_map(map);

    return 0;
}
