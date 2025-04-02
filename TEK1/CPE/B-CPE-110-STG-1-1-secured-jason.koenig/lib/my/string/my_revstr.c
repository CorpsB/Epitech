/*
** EPITECH PROJECT, 2023
** MY_REVSTR
** File description:
** Reverse the order of the characters of a string.
*/

#include "../../../include/my.h"
char *my_revstr(char *str)
{
    int pos_y = my_strlen(str) - 1;
    char tmp;

    for (int pos_x = 0; pos_x < pos_y; ++pos_x){
        tmp = str[pos_x];
        str[pos_x] = str[pos_y];
        str[pos_y] = tmp;
        --pos_y;
    }
    return (str);
}
