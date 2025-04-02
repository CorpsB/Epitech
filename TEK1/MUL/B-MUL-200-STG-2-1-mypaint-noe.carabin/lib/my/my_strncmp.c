/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** my_strncmp
*/

#include "../../includes/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    char n_s1[n];
    char n_s2[n];
    int j = 0;

    for (int i = 0; i < n; i++){
        n_s1[i] = s1[i];
        n_s2[i] = s2[i];
    }
    for (; s1[j] == s2[j] && s1[j] != '\0'; j++){
    }
    return s1[j] - s2[j];
}
