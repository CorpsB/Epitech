/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myhunter-noe.carabin
** File description:
** main2.c
*/

#include "my.h"

void analyse_clic(window_t *game)
{
    sfFloatRect square;
    sfIntRect temp;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);

    for (int i = 1; i < game->entities; i++) {
        square = sfSprite_getGlobalBounds(game->sprite[i]->sprite);
        if (sfFloatRect_contains(&square, (float)mouse.x, (float)mouse.y)) {
            game->sprite[i]->pos = (sfVector2f){-100.00, rand() % 600 + 10};
            sfSprite_setPosition(game->sprite[i]->sprite,
            (sfVector2f)game->sprite[i]->pos);
            game->speed += 1.5;
            game->mouv = (sfVector2f){game->speed, 0.00};
        }
    }
}
