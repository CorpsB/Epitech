/*
** EPITECH PROJECT, 2023
** KJ_ATOMIZE_CHAR
** File description:
** Remove all recurrence of a given character.
*/

#include "../../../include/base/my.h"

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

char *s_remove_index(char *str, int index)
{
    char *result = NULL;
    int length = 0;
    int j = 0;

    length = my_strlen(str);
    result = malloc(sizeof(char) * (length));
    for (int i = 0; str[i] != '\0'; i++){
        if (i != index){
            result[j] = str[i];
        } else
            j--;
        j++;
    }
    result[length - 1] = '\0';
    free(str);
    return result;
}

char *s_remove_last_c(char *str)
{
    int length = 0;
    char *result = NULL;

    length = my_strlen(str);
    if (length == 0)
        return str;
    result = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; i < length - 1; i++)
        result[i] = str[i];
    result[length - 1] = '\0';
    free(str);
    return result;
}
