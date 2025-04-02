/*
** EPITECH PROJECT, 2023
** MY_STRCPY
** File description:
** Copy a string into an other one.
*/

#include "../../../include/project.h"
char *s_copy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

void s_copy_from(char *dest, char const *src, int j)
{
    for (int i = 0; src[i] != '\0'; ++i){
        if (j >= (MEM_SIZE * 2))
            break;
        dest[j] = src[i];
        ++j;
    }
}

void s_copy_from_to(char *dest, char const *src, int j, int k)
{
    int i = 0;

    for (; src[i] != '\0'; ++i){
        if (j >= (MEM_SIZE * 2) && i < k)
            break;
        dest[j] = src[i];
        ++j;
    }
}
