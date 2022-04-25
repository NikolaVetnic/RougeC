#include "map.h"

/* map data */
struct VEC2_ map_size = {.x = 100, .y = 42};
struct VEC2_ map_offset = {.x = 4, .y = 2};

/* map generation parameters */
float chance_to_start_alive = 0.15f;

int death_limit = 1;
int birth_limit = 4;

int num_sim_steps = 5;
int **init_map()
{
    int **map = malloc(map_size.x * sizeof(int *));
    for (int i = 0; i < map_size.x; i++)
        *(map + i) = malloc(map_size.y * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < map_size.x; i++)
        for (int j = 0; j < map_size.y; j++)
            if (i == 0 || i == map_size.x - 1 || j == 0 || j == map_size.y - 1)
                *(*(map + i) + j) = 1;
            else if ((rand() % 100) * 0.01 < chance_to_start_alive)
                *(*(map + i) + j) = 1;

    for (int i = 0; i < num_sim_steps; i++)
        do_sim_step(map);

    return map;
}

int do_sim_step(int **map)
{
    int **old_map = cp_map(map);

    for (int i = 0; i < map_size.x; i++)
    {
        for (int j = 0; j < map_size.y; j++)
        {
            int nbs = count_alive_neighbors(old_map, i, j);

            if (*(*(old_map + i) + j) == 1)
            {
                if (nbs < death_limit)
                    *(*(map + i) + j) = 0;
                else
                    *(*(map + i) + j) = 1;
            }
            else
            {
                if (nbs < birth_limit)
                    *(*(map + i) + j) = 0;
                else
                    *(*(map + i) + j) = 1;
            }
        }
    }

    return 0;
}

int count_alive_neighbors(int **m, int x, int y)
{
    int cnt = 0;

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
                continue;

            struct VEC2_ n = {.x = x + i, .y = y + j};

            if (n.x < 0 || n.x >= map_size.x || n.y < 0 || n.y >= map_size.y)
                cnt++; /* outside of map borders counts as alive */
            else       /* neighbor is alive */
                cnt += *(*(m + x + i) + y + j);
        }
    }

    return cnt;
}

int **cp_map(int **map)
{
    int **new_map = malloc(map_size.x * sizeof(int *));
    for (int i = 0; i < map_size.x; i++)
        *(new_map + i) = malloc(map_size.y * sizeof(int));

    for (int i = 0; i < map_size.x; i++)
        for (int j = 0; j < map_size.y; j++)
            *(*(new_map + i) + j) = *(*(map + i) + j);

    return new_map;
}

int draw_map(int **map)
{
    for (int i = 0; i < map_size.x; i++)
        for (int j = 0; j < map_size.y; j++)
            if (*(*(map + i) + j) == 1)
                mvprintw(j + map_offset.y, i + map_offset.x, t_wall());
            else
                mvprintw(j + map_offset.y, i + map_offset.x, t_ground());

    return 0;
}