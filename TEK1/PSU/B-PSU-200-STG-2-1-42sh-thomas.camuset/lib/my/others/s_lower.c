/*
** EPITECH PROJECT, 2023
** MY_STRLOWCASE
** File description:
** Put a string lowercase.
*/

#include "../../../include/base/my.h"
char *s_lower(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    return (str);
}
