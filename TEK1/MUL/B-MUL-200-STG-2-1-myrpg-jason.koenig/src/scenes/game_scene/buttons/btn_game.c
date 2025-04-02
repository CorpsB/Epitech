/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_game.c
*/

#include "../../../../include/csfml.h"

void btn_game(button_t *button)
{
    button->gui->is_echap = false;
    button->gui->player.dialog->is_hide = sfFalse;
}
