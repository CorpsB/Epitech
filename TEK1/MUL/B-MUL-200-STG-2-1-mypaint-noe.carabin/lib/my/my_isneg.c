/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** my_isneg
*/

#include "../../includes/my.h"

int my_isneg(int number)
{
    if (number >= 0){
        my_putchar(80);
    } else {
        my_putchar(78);
    }
}
