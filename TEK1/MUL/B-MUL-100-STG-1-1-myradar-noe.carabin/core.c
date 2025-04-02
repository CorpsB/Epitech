/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-noe.carabin
** File description:
** core.c
*/

#include "my.h"

static void analyse_events(game_t *game, plane_t *plane, tower_t *tower)
{
    while (sfRenderWindow_pollEvent(game->win, &(game->event)))
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->win);
}

static sfSprite* background(void)
{
    sfVector2f pos_b = {0, 0};
    sfVector2f size = {1.09, 1};
    sfTexture* texture = sfTexture_createFromFile("sprite/back.png", NULL);
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, size);
    return sprite;
}

static void draw_all_plane(game_t *game, plane_t *plane)
{
    sfVector2f pos_b;
    plane_t *tmp = plane;

    while (tmp != NULL){
        if (tmp->isalive) {
            pos_b.x = tmp->start_x;
            pos_b.y = tmp->start_y;
            sfSprite_setPosition(tmp->plane, pos_b);
            sfRectangleShape_setPosition(tmp->hit_box, pos_b);
            sfRenderWindow_drawSprite(game->win, tmp->plane, NULL);
            sfRenderWindow_drawRectangleShape(game->win, tmp->hit_box, NULL);
        }
        tmp = tmp->next;
    }
}

static void mooving_sprite(plane_t *plane, game_t *game)
{
    plane_t *tmp;

    tmp = plane;
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) >= 1){
        while (tmp != NULL){
            tmp->start_x += (tmp->norm.x * tmp->speed);
            tmp->start_y += (tmp->norm.y * tmp->speed);
            tmp = tmp->next;
        }
        sfClock_restart(game->clock);
    }
}

void core(game_t *game, plane_t *plane, tower_t *tower)
{
    sfSprite *sprite = background();

    while (sfRenderWindow_isOpen(game->win)){
        analyse_events(game, plane, tower);
        check_colision(plane, game);
        mooving_sprite(plane, game);
        sfRenderWindow_clear(game->win, sfBlack);
        sfRenderWindow_drawSprite(game->win, sprite, NULL);
        draw_all_plane(game, plane);
        sfRenderWindow_display(game->win);
    }
}
