/*
** EPITECH PROJECT, 2024
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** battler
*/

#include "../../../include/csfml.h"

static int get_mob_attack(int id, int lvl)
{
    if (id == MINOTAUR)
        return 2.97 * lvl;
}

static int get_mob_defense(int id, int lvl)
{
    if (id == MINOTAUR)
        return 1.94 * lvl;
}

static int get_mob_luck(int id, int lvl)
{
    if (id == MINOTAUR)
        return 0.58 * lvl;
}

static int get_mob_health(int id, int lvl)
{
    if (id == MINOTAUR)
        return 44.68 * lvl;
}

static int get_mob_xp(int id, int lvl)
{
    if (id == MINOTAUR)
        return 9.31 * lvl;
}

static char *get_path_name(int id)
{
    if (id == MINOTAUR)
        return my_strdup("assets/battler/1.png");
}

static char *get_ennemy_name(int id)
{
    if (id == MINOTAUR)
        return my_strdup("Minotaur");
}

ennemy_t *create_ennemy(gui_t *gui, int id, int lvl)
{
    ennemy_t *bat = malloc(sizeof(ennemy_t));
    char *path = get_path_name(id);
    sfIntRect rect = {0, 0, 120, 120};

    bat->name = get_ennemy_name(id);
    bat->sprite = create_csfml_sprite(path,
    &(sfVector2f){gui->graphics.win_size.x / 2,
    gui->graphics.win_size.y / 2 + 100}, &rect);
    sfSprite_setScale(bat->sprite->sprite, (sfVector2f){3, 3});
    bat->stats.attack = get_mob_attack(id, lvl);
    bat->stats.defense = get_mob_defense(id, lvl);
    bat->stats.luck = get_mob_luck(id, lvl);
    bat->stats.experience = get_mob_xp(id, lvl);
    bat->stats.health = get_mob_health(id, lvl);
    bat->stats.level = lvl;
    free(path);
    return bat;
}
