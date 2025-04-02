/*
** EPITECH PROJECT, 2023
** MY_STRCAT
** File description:
** Concat two strings.
*/

#include "../../../include/base/my.h"
char *my_strcat(char *dest, char const *src)
{
    char *result = malloc((sizeof(char) * (my_strlen(dest) +
    my_strlen(src))) + 1);
    int j = 0;

    if (result == NULL)
        return NULL;
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

char *my_strcat_no_free(char *dest, char const *src)
{
    char *result = malloc((sizeof(char) * (my_strlen(dest) +
    my_strlen(src))) + 1);
    int j = 0;

    if (result == NULL)
        return NULL;
    for (int i = 0; dest[i] != '\0'; ++i){
        result[j] = dest[i];
        ++j;
    }
    for (int i = 0; src[i] != '\0'; ++i){
        result[j] = src[i];
        ++j;
    }
    result[j] = '\0';
    return (result);
}

char *s_sepmerge(char *dest, char const *src, char sep)
{
    char *result = malloc((sizeof(char) * my_strlen(dest) +
    my_strlen(src) + 2));
    int j = 0;

    for (int i = 0; dest[i] != '\0'; ++i){
        result[j] = dest[i];
        ++j;
    }
    result[j] = sep;
    ++j;
    for (int i = 0; src[i] != '\0'; ++i){
        result[j] = src[i];
        ++j;
    }
    result[j] = '\0';
    free(dest);
    return (result);
}

char *s_sependmerge(char *dest, char const *src, char sep)
{
    char *result = malloc((sizeof(char) * my_strlen(dest) +
    my_strlen(src) + 2));
    int j = 0;

    for (int i = 0; dest[i] != '\0'; ++i){
        result[j] = dest[i];
        ++j;
    }
    for (int i = 0; src[i] != '\0'; ++i){
        result[j] = src[i];
        ++j;
    }
    result[j] = sep;
    ++j;
    result[j] = '\0';
    free(dest);
    return (result);
}

char *s_concat_c(char *str, char c)
{
    char *result = NULL;

    result = malloc(sizeof(char) * (my_strlen(str) + 1) + 1);
    for (int i = 0; str[i] != '\0'; i++)
        result[i] = str[i];
    result[my_strlen(str)] = c;
    result[my_strlen(str) + 1] = '\0';
    free(str);
    return result;
}
