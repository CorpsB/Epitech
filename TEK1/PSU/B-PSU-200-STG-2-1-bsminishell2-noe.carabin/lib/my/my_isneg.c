/*
** EPITECH PROJECT, 2023
** ISNEG
** File description:
** display if the number is positive or negative
*/

#include "../my.h"

/**
 * La fonction renvoie un booléens true si le nombre est négatif, false dans
 * le cas contraire.
*/
bool my_isneg(int n)
{
    if (n >= 0){
        return false;
    } else {
        return true;
    }
}
