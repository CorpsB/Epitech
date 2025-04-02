/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_play.c
*/

#include "../../../../include/csfml.h"

void btn_play(button_t *button)
{
    button->gui->selected = select_scene(button->gui, GAME_SCENE);
    button->gui->is_echap = false;
}
