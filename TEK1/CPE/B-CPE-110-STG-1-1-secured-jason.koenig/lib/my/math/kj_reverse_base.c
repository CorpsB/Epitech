/*
** EPITECH PROJECT, 2023
** KJ_REVERSE_BASE
** File description:
** Put a number back into base 10.
*/

#include "../../../include/my.h"
const char symboles[] = "0123456789abcdefghijklmnopqrstuvwxyz";

long long kj_reverse_base(char *nb, int base)
{
    int result = 0;
    int size = my_strlen(nb) - 1;
    int j = 0;

    for (int i = 0; nb[i] != '\0'; ++i){
        for (j = 0; symboles[j] != nb[i]; ++j);
        result += (j * kj_xposant(base, size - i));
    }
    return (result);
}
