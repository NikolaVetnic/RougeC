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

        // TODO: change player position to Vec2
        Vec2 src = {.x = user->x_pos, .y = user->y_pos};
        Vec2 dst = {.x = (int)(fov_rad * cos(ang)) + user->x_pos, .y = (int)(fov_rad * sin(ang)) + user->y_pos};

        line_to_buf(fov_buf, &fov_len, src, dst);
    }
}

void draw_visible(Player *user, int show_buf_len)
{
    for (int i = 0; i < fov_len; i++)
        mvprintw(fov_buf[i].y, fov_buf[i].x, t_visible());

    mvprintw(user->y_pos, user->x_pos, t_pc());
    move(user->y_pos, user->x_pos);

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

    move(user->y_pos, user->x_pos); /* reset pointer to PC */

    return 0;
}