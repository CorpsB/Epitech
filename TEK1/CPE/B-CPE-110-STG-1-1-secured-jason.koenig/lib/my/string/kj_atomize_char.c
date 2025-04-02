/*
** EPITECH PROJECT, 2023
** KJ_ATOMIZE_CHAR
** File description:
** Remove all recurrence of a given character.
*/

#include "../../../include/my.h"
char *kj_atomize_char(char *str, char c, int i, int k)
{
    char *result;
    char carac[2];

    carac[1] = '\0';
    for (int j = 0; str[j] != '\0'; ++j){
        carac[0] = str[j];
        if (str[j] != c || i > j || j > k)
            result = my_strcat(result, carac);
    }
    result = my_revstr(result);
    return (result);
}
