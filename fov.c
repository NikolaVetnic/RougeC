#include "fov.h"

Vec2 fov_buf[FOV_LEN_MAX]; /* visible tiles from current position, i.e. FOV buffer */
int fov_len = 0;           /* current length of FOV buffer */
int fov_rad = 200;         /* field of view radius */
int fov_stp = 100;         /* field of view angle step count */

void reset_visible()
{
    for (int i = 0; i < fov_len; i++)
        mvprintw(fov_buf[i].y, fov_buf[i].x, t_ground());

    fov_len = 0;
}

void populate_visible(Player *user)
{
    float div = TURN_IN_RAD / fov_stp;

    for (int i = 0; i < fov_stp; i++)
    {
        float ang = i * div;
        Vec2 dst = {.x = (int)(fov_rad * cos(ang)) + user->pos.x, .y = (int)(fov_rad * sin(ang)) + user->pos.y};

        line_to_buf(fov_buf, &fov_len, user->pos, dst);
    }
}

void draw_visible(Player *user, int show_buf_len)
{
    for (int i = 0; i < fov_len; i++)
        mvprintw(fov_buf[i].y, fov_buf[i].x, t_visible());

    mvprintw(user->pos.y, user->pos.x, t_pc());
    move(user->pos.y, user->pos.x);

    if (show_buf_len)
    {
        char str[20];
        sprintf(str, "FOV_LEN : %d", fov_len);

        mvprintw(0, 0, str);
    }
}

int draw_fov(Player *user)
{
    reset_visible();
    populate_visible(user);
    draw_visible(user, 1);

    move(user->pos.y, user->pos.x); /* reset pointer to PC */

    return 0;
}