/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** menu.c
*/

#include "../../../../include/csfml.h"

static void launch_attack(gui_t *gui, battler_t *attack, battler_t *defense,
    int val)
{
    int ennemy_def = defense->defense * defense->level;
    int player_atk = (attack->attack + val * 0.1) * attack->level;
    int damages = player_atk - ennemy_def;

    if (damages < 0)
        return;
    defense->health -= damages;
}

void btn_normal_attack(button_t *button)
{
    ennemy_t *ennemy = button->gui->selected->data_list->element;

    button->gui->player.utimate_energy += 10;
    button->gui->player.energy++;
    if (button->gui->player.energy > 15)
        button->gui->player.energy = 15;
    launch_attack(button->gui, &button->gui->player.stats, &ennemy->stats, 10);
    if (ennemy->stats.health > 0)
        launch_attack(button->gui, &ennemy->stats, &button->gui->player.stats,
        (ennemy->stats.attack * 15 * 5.5 - ennemy->stats.health) / 2);
}

void btn_skill_attack(button_t *button)
{
    ennemy_t *ennemy = button->gui->selected->data_list->element;

    button->gui->player.utimate_energy += 35;
    if (button->gui->player.utimate_energy > 100)
        button->gui->player.utimate_energy = 100;
    button->gui->player.energy -= 3;
    launch_attack(button->gui, &button->gui->player.stats, &ennemy->stats, 40);
    if (ennemy->stats.health > 0)
        launch_attack(button->gui, &ennemy->stats, &button->gui->player.stats,
        (ennemy->stats.attack * 15 * 5.5 - ennemy->stats.health) / 2);
}

void btn_ultimate_attack(button_t *button)
{
    button->gui->player.utimate_energy = 5;
    button->gui->player.stats.attack *= 2;
    button->gui->player.stats.defense *= 2;
}
