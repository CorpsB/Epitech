/*
** EPITECH PROJECT, 2023
** my_int_to_char
** File description:
** my_int_to_char
*/

#include "../../includes/my.h"

char *tc_my_int_to_str(long long int nb)
{
    char *str;
    char c[] = " ";
    long long int nb_tmp = nb;
    linked_list_t *list = NULL;

    if (nb < 0)
        nb = -nb;
    while ((double)nb / 10.0 > 0.0){
        c[0] = 48 + nb % 10;
        kj_put_in_chain(&list, c);
        nb /= 10;
    }
    if (nb_tmp < 0)
        kj_put_in_chain(&list, "-");
    str = kj_chain_to_str(list);
    kj_free_list(list);
    return str;
}
