/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_less.c
*/

#include "../../../../include/csfml.h"

void btn_less(button_t *button)
{
    float sound = sfListener_getGlobalVolume();

    if (sound != (float)0)
        sfListener_setGlobalVolume(sound - 10);
}
