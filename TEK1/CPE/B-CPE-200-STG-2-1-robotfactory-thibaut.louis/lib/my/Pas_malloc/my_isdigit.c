/*
** EPITECH PROJECT, 2023
** B-CPE-110-STG-1-1-organized-thibaut.louis
** File description:
** my_isdigit.c
*/

#include "../../my.h"

int my_isdigit(int c)
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}
