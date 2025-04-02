/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_forward.c
*/

#include "../../../../include/csfml.h"

void btn_for(button_t *butttton)
{
    butttton->gui->controls.mvt_up = get_key(butttton);
}
