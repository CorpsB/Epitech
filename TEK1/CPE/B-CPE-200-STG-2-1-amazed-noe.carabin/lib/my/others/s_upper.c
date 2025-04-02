/*
** EPITECH PROJECT, 2023
** MY_STRUPCASE
** File description:
** Put a string into uppercase.
*/

#include "../../../include/my.h"
char *s_upper(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return (str);
}
