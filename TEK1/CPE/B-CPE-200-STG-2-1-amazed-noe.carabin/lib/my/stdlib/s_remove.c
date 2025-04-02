/*
** EPITECH PROJECT, 2023
** KJ_ATOMIZE_CHAR
** File description:
** Remove all recurrence of a given character.
*/

#include "../../../include/my.h"
char *s_remove(char *str, char c)
{
    char *result;
    char carac[2];

    carac[1] = '\0';
    for (int i = 0; str[i] != '\0'; ++i){
        carac[0] = str[i];
        if (str[i] != c)
            result = my_strcat(result, carac);
    }
    return (result);
}
