/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_action2.c
*/

#include "../../../../include/csfml.h"

void btn_act2(button_t *butttton)
{
    butttton->gui->controls.act_2 = get_key(butttton);
}
