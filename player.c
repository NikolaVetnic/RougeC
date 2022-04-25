#include "player.h"

Player *player_setup(Vec2 start_pos)
{
    Player *new_player;
    new_player = malloc(sizeof(Player));

    new_player->pos = start_pos;
    new_player->health = 20;

    player_move(new_player->pos, new_player);

    return new_player;
}

int handle_input(int input, Player *user)
{
    Vec2 new_pos = {.x = user->pos.x, .y = user->pos.y};

    int new_x = user->pos.x;
    int new_y = user->pos.y;

    switch (input)
    {
    case 'w':
    case 'W':
        new_pos.y--;
        break;

    case 'a':
    case 'A':
        new_pos.x--;
        break;

    case 's':
    case 'S':
        new_pos.y++;
        break;

    case 'd':
    case 'D':
        new_pos.x++;
        break;

    default:
        break;
    }

    if (can_move(new_pos, user) == 0)
        player_move(new_pos, user);
    else /* prevents cursor from going into walls */
        move(user->pos.y, user->pos.x);

    return 0;
}

int player_move(Vec2 pos, Player *user)
{
    mvprintw(user->pos.y, user->pos.x, t_ground());

    user->pos = pos;

    draw_fov(user);

    return 0;
}

int can_move(Vec2 pos, Player *user)
{
    if (mvinch(pos.y, pos.x) == t_visible()[0])
        return 0;

    return -1;
}