/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../../include/project.h"

char *get_hexa_base(int nb, int size)
{
    char *new = n_base(nb, 16);
    int new_size = my_strlen(new);
    int miss = size - new_size;
    char *res;
    int j = 0;

    if (miss == 0)
        return new;
    res = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < miss; ++i){
        res[j] = '0';
        ++j;
    }
    for (int i = 0; i < new_size; ++i){
        res[j] = new[i];
        ++j;
    }
    res[j] = '\0';
    free(new);
    return res;
}
