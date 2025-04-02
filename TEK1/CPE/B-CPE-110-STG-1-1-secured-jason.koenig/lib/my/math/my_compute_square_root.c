/*
** EPITECH PROJECT, 2023
** MY_COMPUTE_SQUARE_ROOT
** File description:
** Return the square root of a number.
*/

#include "../../../include/my.h"
int my_compute_square_root(int nb)
{
    if (nb == 1)
        return (1);
    for (int i = 1; i <= (nb / 2); ++i)
        if ((i * i) == nb)
            return (i);
    return (0);
}
