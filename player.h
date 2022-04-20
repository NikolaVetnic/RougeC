typedef struct PLAYER_
{
    int x_pos;
    int y_pos;
    int health;
} Player;

Player *player_setup();
int handle_input(int input, Player *user);
int player_move(int y, int x, Player *user);
int can_move(int new_y, int new_x, Player *user);

Player *player_setup()
{
    Player *new_player;
    new_player = malloc(sizeof(Player));

    new_player->x_pos = 14;
    new_player->y_pos = 14;
    new_player->health = 20;

    player_move(14, 14, new_player);

    return new_player;
}

int handle_input(int input, Player *user)
{
    int new_x = user->x_pos;
    int new_y = user->y_pos;

    switch (input)
    {
    case 'w':
    case 'W':
        new_y--;
        break;

    case 'a':
    case 'A':
        new_x--;
        break;

    case 's':
    case 'S':
        new_y++;
        break;

    case 'd':
    case 'D':
        new_x++;
        break;

    default:
        break;
    }

    if (can_move(new_y, new_x, user) == 0)
        player_move(new_y, new_x, user);
    else /* prevents cursor from going into walls */
        move(user->y_pos, user->x_pos);

    return 0;
}

int player_move(int y, int x, Player *user)
{
    mvprintw(user->y_pos, user->x_pos, T_GROUND);

    user->y_pos = y;
    user->x_pos = x;

    mvprintw(user->y_pos, user->x_pos, T_PC);
    move(user->y_pos, user->x_pos);

    return 0;
}

int can_move(int new_y, int new_x, Player *user)
{
    if (mvinch(new_y, new_x) == T_GROUND[0])
        return 0;

    return -1;
}