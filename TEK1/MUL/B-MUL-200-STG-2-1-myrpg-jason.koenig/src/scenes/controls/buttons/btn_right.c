/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_right.c
*/

#include "../../../../include/csfml.h"

void btn_right(button_t *butttton)
{
    butttton->gui->controls.mvt_right = get_key(butttton);
}
