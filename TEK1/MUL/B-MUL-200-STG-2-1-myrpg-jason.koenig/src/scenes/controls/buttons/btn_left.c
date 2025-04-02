/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_left.c
*/

#include "../../../../include/csfml.h"

void btn_left(button_t *butttton)
{
    butttton->gui->controls.mvt_left = get_key(butttton);
}
