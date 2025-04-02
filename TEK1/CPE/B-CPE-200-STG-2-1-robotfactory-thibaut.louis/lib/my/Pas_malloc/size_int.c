/*
** EPITECH PROJECT, 2023
** B-CPE-210-STG-2-1-solostumper05-thibaut.louis
** File description:
** size_int.c
*/

#include "../../my.h"

int int_size(long long int nbr)
{
    int result = 1;

    for (; nbr / 10 >= 1; result++){
        nbr = nbr / 10;
    }
    return (result);
}
