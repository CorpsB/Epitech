/*
** EPITECH PROJECT, 2023
** MY_STR_ISNUM
** File description:
** Check if the given string contains only numbers.
*/

#include "../../../include/my.h"
int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    return (1);
}
