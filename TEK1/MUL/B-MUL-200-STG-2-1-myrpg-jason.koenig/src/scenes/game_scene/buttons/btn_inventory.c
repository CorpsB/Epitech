/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_inventory.c
*/

#include "../../../../include/csfml.h"

void btn_inventory(button_t *button)
{
    button->gui->selected = select_scene(button->gui, INVENTORY);
}
