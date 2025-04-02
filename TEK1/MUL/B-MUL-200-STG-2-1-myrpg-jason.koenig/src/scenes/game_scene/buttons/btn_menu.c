/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** menu.c
*/

#include "../../../../include/csfml.h"

void btn_menu(button_t *button)
{
    button->gui->selected = select_scene(button->gui, MAIN_MENU);
}
