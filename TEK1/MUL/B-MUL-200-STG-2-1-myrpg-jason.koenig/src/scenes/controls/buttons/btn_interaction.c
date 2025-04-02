/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_interaction.c
*/

#include "../../../../include/csfml.h"

void btn_int(button_t *butttton)
{
    butttton->gui->controls.interact = get_key(butttton);
}
