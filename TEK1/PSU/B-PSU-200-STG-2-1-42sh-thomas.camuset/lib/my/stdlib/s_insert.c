/*
** EPITECH PROJECT, 2024
** B-PSU-200-STG-2-1-42sh-thomas.camuset
** File description:
** s_insert
*/

#include "../../../include/base/my.h"

static void modify_result(char **dest, char *src, int index, char c)
{
    int j = 0;

    for (int i = 0; src[i] != '\0'; i++){
        if (i == index){
            (*dest)[j] = c;
            j++;
        }
        (*dest)[j] = src[i];
        j++;
    }
}

char *s_insert(char *str, char c, int index)
{
    char *result = NULL;
    char single[2];
    int length = strlen(str);

    single[0] = c;
    single[1] = '\0';
    if (length == 0){
        free(str);
        return my_strdup(single);
    }
    if (index == length){
        result = my_strcat(str, single);
        return result;
    }
    result = malloc(sizeof(char) * (length + 2));
    modify_result(&result, str, index, c);
    result[length + 1] = '\0';
    free(str);
    return result;
}

static void s_insert_s_next(char *dest, char **result, int *j)
{
    for (int k = 0; dest[k] != '\0'; k++){
        (*result)[*j] = dest[k];
        (*j)++;
    }
}

char *s_insert_s(char *src, char *dest, int index)
{
    char *result = NULL;
    int j = 0;

    if (index < 0 || index > strlen(src))
        return NULL;
    if (index == strlen(src))
        return my_strcat(src, dest);
    result = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));
    for (int i = 0; src[i] != '\0'; i++){
        if (i == index)
            s_insert_s_next(dest, &result, &j);
        result[j] = src[i];
        j++;
    }
    return result;
}
