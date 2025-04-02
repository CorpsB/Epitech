/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** map_pannel
*/

#include "../../../../include/csfml.h"

static csfml_sprite_t *create_map_col(char *map_path, sfVector2f *pos,
    char *type)
{
    csfml_sprite_t *map_col;
    char *new_path = my_substr(map_path, 0, my_strlen(map_path) - 4);

    new_path = my_strcat(new_path, type);
    map_col = create_csfml_sprite(new_path, pos, NULL);
    free(new_path);
    return map_col;
}

void create_map_pannel(pannel_t *pannels, char *map_path, sfVector2f *pos)
{
    csfml_sprite_t *map = create_csfml_sprite(map_path, pos, NULL);

    sfSprite_setOrigin(map->sprite, (sfVector2f){655.5f, 1632});
    create_data(&pannels->element, map);
}

void create_map_pannel2(pannel_t *pannels, char *map_path, sfVector2f *pos)
{
    csfml_sprite_t *map_up = create_map_col(map_path, pos, "_up.png");

    sfSprite_setOrigin(map_up->sprite, (sfVector2f){655.5f, 1632});
    create_data(&pannels->element, map_up);
}
