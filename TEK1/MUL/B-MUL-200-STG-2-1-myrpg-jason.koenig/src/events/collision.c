/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** collision
*/

#include "../../include/csfml.h"

//Meilleur grace à moi ...
sfBool is_rectangle_collision(sfRectangleShape* rect1, sfRectangleShape* rect2)
{
    sfFloatRect hit1 = sfRectangleShape_getGlobalBounds(rect1);
    sfFloatRect hit2 = sfRectangleShape_getGlobalBounds(rect2);

    if (sfFloatRect_intersects(&hit1, &hit2, NULL))
        return sfTrue;
    return sfFalse;
}

sfBool is_collision_map(player_t *player, int x, int y)
{
    if (x > 0)
        x = 1;
    else if (x < 0)
        x = -1;
    if (y > 0)
        y = 1;
    else if (y < 0)
        y = -1;
    if (player->collision_map[player->pos_map.y - y][player->pos_map.x - x]
    == ' '){
        player->pos_map.x -= x;
        player->pos_map.y -= y;
        return sfFalse;
    }
    return sfTrue;
}
