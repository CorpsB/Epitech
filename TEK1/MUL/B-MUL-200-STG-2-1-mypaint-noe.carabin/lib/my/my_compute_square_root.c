/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** my_compute_square_root
*/

#include "../../includes/my.h"

int my_compute_square_root(int nb)
{
    if (nb <= 0){
        return 0;
    }
    if (nb == 1){
        return 1;
    }
    for (int i = 1; i <= nb / 2; i++){
        if (i * i == nb){
            return i;
        } else {
            return 0;
        }
    }
    return 0;
}
