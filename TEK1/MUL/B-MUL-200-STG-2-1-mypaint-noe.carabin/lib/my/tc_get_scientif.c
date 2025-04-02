/*
** EPITECH PROJECT, 2023
** TC_PUTSCIENTIF
** File description:
** Put a float number to scientif.
*/

#include "../../includes/my.h"

static void str_to_list(linked_list_t **list, char *str)
{
    char carac[] = " ";

    for (int i = 0; str[i] != '\0'; ++i){
        carac[0] = str[i];
        kj_put_in_chain(list, carac);
    }
}

static char *tc_get_scientif_2(double nb, char *exp_sign,
    int *multipl_virg, linked_list_t *list)
{
    char *result;

    if (nb > 9.999999){
        nb = (double)nb / 10.0;
        multipl_virg[0]++;
    }
    result = kj_getfloat(nb, multipl_virg[1]);
    str_to_list(&list, result);
    free(result);
    kj_put_in_chain(&list, "e");
    kj_put_in_chain(&list, exp_sign);
    if (multipl_virg[0] <= 9)
        kj_put_in_chain(&list, "0");
    result = tc_my_int_to_str(multipl_virg[0]);
    str_to_list(&list, result);
    free(result);
    my_rev_list(&list);
    result = kj_chain_to_str(list);
    kj_free_list(list);
    return (result);
}

char *tc_get_scientif(double nb, int virg)
{
    int multipl_virg[] = {0, virg};
    char exp_sign[] = "+";
    char sign = '+';
    linked_list_t *list = NULL;

    if (nb < 0){
        kj_put_in_chain(&list, "-");
        nb = -nb;
    }
    if (nb > 0 && nb < 1){
        for (; nb < 1.0; multipl_virg[0]++)
            nb *= 10;
        exp_sign[0] = '-';
    } else {
        for (; nb >= 10; multipl_virg[0]++)
            nb = (double)(nb / 10.0);
    }
    return (tc_get_scientif_2(nb, exp_sign,
    multipl_virg, list));
}
