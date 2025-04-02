/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "../../includes/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int length1 = my_strlen(s1);
    int length2 = my_strlen(s2);
    int length = 0;

    if (length1 > length2)
        length = length2;
    else
        length = length1;
    for (int i = 0; i < length; i++){
        if (s1[i] > s2[i])
            return 1;
        if (s2[i] > s1[i])
            return -1;
    }
    if (length1 == length2)
        return 0;
    else if (length1 > length2)
        return 1;
    else
        return -1;
}
