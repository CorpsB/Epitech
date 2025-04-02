/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_backward.c
*/

#include "../../../../include/csfml.h"

void btn_back(button_t *butttton)
{
    butttton->gui->controls.mvt_down = get_key(butttton);
}
