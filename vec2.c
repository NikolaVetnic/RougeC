#include "vec2.h"

int add(Vec2 v0, Vec2 v1)
{
    return 0;
}

int vec2equal(Vec2 v0, Vec2 v1)
{
    if (v0.x == v1.x && v0.y == v1.y)
        return 1;

    return 0;
}

void line_to_buf(Vec2 *buf, int *curr_len, Vec2 v0, Vec2 v1)
{
    Vec2 pd = {.x = v1.x - v0.x, .y = v1.y - v0.y};

    Vec2 d0 = {.x = 0, .y = 0};
    Vec2 d1 = {.x = 0, .y = 0};

    d0.x = pd.x < 0 ? -1 : pd.x == 0 ? 0
                                     : 1;
    d0.y = pd.y < 0 ? -1 : pd.y == 0 ? 0
                                     : 1;
    d1.x = pd.x < 0 ? -1 : pd.x == 0 ? 0
                                     : 1;

    int longest = abs(pd.x);
    int shortest = abs(pd.y);

    if (longest <= shortest)
    {
        longest = abs(pd.y);
        shortest = abs(pd.x);

        d1.x = 0;
        d1.y = pd.y < 0 ? -1 : pd.y == 0 ? 0
                                         : 1;
    }

    int numerator = longest >> 1;

    for (int i = 0; i <= longest; i++)
    {
        if (mvinch(v0.y, v0.x) == t_ground()[0] || mvinch(v0.y, v0.x) == t_visible()[0])
        {
            int contains = 0;

            for (int j = 0; j < *curr_len; j++)
                if (buf[j].x == v0.x && buf[j].y == v0.y)
                {
                    contains = 1;
                    break;
                }

            if (!contains)
            {
                buf[*curr_len].x = v0.x;
                buf[*curr_len].y = v0.y;
                *curr_len = *curr_len + 1;
            }

            numerator += shortest;

            if (numerator >= longest)
            {
                numerator -= longest;
                v0.x += d0.x;
                v0.y += d0.y;
            }
            else
            {
                v0.x += d1.x;
                v0.y += d1.y;
            }
        }
        else
        {
            break;
        }
    }
}