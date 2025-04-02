/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../include/project.h"

int get_average(char **table, int start, int end)
{
    int result = 0;

    start += 2;
    end += 2;
    for (int i = start; i <= end; i++)
        result += atoi(table[i]);
    return (result / (end - start));
}

int get_third_side(int side1, int side2, float angle)
{
    return sqrt(pow(side1, 2) +
    pow(side2, 2) - (2 * side1 * side2 * cos(angle)));
}
