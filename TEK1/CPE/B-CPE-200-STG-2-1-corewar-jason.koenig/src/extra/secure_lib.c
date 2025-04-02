/*
** EPITECH PROJECT, 2024
** SECURE LIB
** File description:
** Execute lib functions with error handling.
*/

#include "../../include/project.h"

int secure_getnbr(int *stock, char *val)
{
    int size_str;
    int size_int;

    *stock = n_convert_s(val);
    size_str = my_strlen(val);
    size_int = n_size(*stock);
    if (size_int != size_str)
        return 1;
    return 0;
}
