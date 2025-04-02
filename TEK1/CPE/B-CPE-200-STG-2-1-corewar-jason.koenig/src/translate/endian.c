/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../../include/project.h"

unsigned int rev_endian(unsigned int val)
{
    return ((val & 0x000000FF) << 24) |
    ((val & 0x0000FF00) << 8) |
    ((val & 0x00FF0000) >> 8) |
    ((val & 0xFF000000) >> 24);
}

int lrev_endian(int val)
{
    return (((val & 0x00FF) << 8) |
    ((val & 0xFF00) >> 8));
}
