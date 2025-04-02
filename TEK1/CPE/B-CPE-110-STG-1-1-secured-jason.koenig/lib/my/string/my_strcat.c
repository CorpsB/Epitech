/*
** EPITECH PROJECT, 2023
** MY_STRCAT
** File description:
** Concat two strings.
*/

#include "../../../include/my.h"
char *my_strcat(char *dest, char const *src)
{
    char *result = malloc((sizeof(char) * (my_strlen(dest) +
    my_strlen(src))) + 1);
    int j = 0;

    for (int i = 0; dest[i] != '\0'; ++i){
        result[j] = dest[i];
        ++j;
    }
    for (int i = 0; src[i] != '\0'; ++i){
        result[j] = src[i];
        ++j;
    }
    result[j] = '\0';
    free(dest);
    return (result);
}
