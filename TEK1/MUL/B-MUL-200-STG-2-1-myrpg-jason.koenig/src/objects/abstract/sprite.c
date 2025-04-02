/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** create_sprite
*/

#include "../../../include/csfml.h"

csfml_sprite_t *create_csfml_sprite(char *text, sfVector2f *pos,
    sfIntRect *area)
{
    csfml_sprite_t *sprite = malloc(sizeof(csfml_sprite_t));

    sprite->texture = sfTexture_createFromFile(text, NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    if (area != NULL)
        sfSprite_setTextureRect(sprite->sprite, *area);
    sfSprite_setOrigin(sprite->sprite,
        (sfVector2f){sfSprite_getGlobalBounds(sprite->sprite).width / 2,
        sfSprite_getGlobalBounds(sprite->sprite).height / 2});
    sfSprite_setPosition(sprite->sprite, *pos);
    sfSprite_setScale(sprite->sprite, (sfVector2f){1.3f, 1.3f});
    sprite->pos.x = pos->x;
    sprite->pos.y = pos->y;
    return sprite;
}

void destroy_csfml_sprite(csfml_sprite_t *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
}
