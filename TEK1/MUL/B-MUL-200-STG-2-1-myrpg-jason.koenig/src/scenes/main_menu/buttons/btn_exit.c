/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-jason.koenig
** File description:
** btn_exit.c
*/

#include "../../../../include/csfml.h"

void btn_exit(button_t *button)
{
    destroy_gui(button->gui, sfTrue);
    exit(0);
}
