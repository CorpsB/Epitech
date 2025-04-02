/*
** EPITECH PROJECT, 2023
** MY_PUTFLOAT
** File description:
** Return a float_number.
*/

#include "../../includes/my.h"

static void kj_subzero_to_chain(linked_list_t **list, int i, int virg)
{
    char carac[] = "#";

    for (; i < virg + 1; ++i){
        carac[0] = '0';
        kj_put_in_chain(list, carac);
    }
}

static int kj_number_to_chain(linked_list_t **list,
    unsigned long long int nb, int nb_size)
{
    char carac[] = "#";
    int number;
    int i = 0;

    while (nb_size > 0){
        number = (int)(nb / kj_xposant(10, nb_size - 1));
        carac[0] = 48 + number;
        nb -= (number * kj_xposant(10, nb_size - 1));
        --nb_size;
        ++i;
        kj_put_in_chain(list, carac);
    }
    return (i);
}

static void kj_insert_float(linked_list_t **result, double nb, int virg)
{
    int nb_size = kj_count_number(nb / 1);
    unsigned long long int num = (unsigned long long int)(nb / 1);
    unsigned long long int num2;
    int i;

    nb -= ((unsigned long long int)(nb / 1));
    nb *= kj_xposant(10, virg);
    num2 = (unsigned long long int)(nb / 1);
    kj_put_in_chain(result, "0");
    kj_number_to_chain(result, num, nb_size);
    kj_put_in_chain(result, ".");
    i = kj_number_to_chain(result, num2, virg);
    kj_subzero_to_chain(result, i, virg);
}

static void do_round_sup(char *str, int i, int i_max, int reste)
{
    if (str[i] == '.')
        --i;
    if (str[i] + reste > '9' || (i == i_max && str[i] >= '5')){
        str[i] = '0';
        reste = 1;
        do_round_sup(str, i - 1, i_max, reste);
    } else {
        str[i] += reste;
    }
}

static char *kj_putfloat_print(char *res, int res_size)
{
    char *resu;
    int i_start = 0;

    if (res[0] == '0')
        ++i_start;
    if (res[0] == '-' && res[1] == '0'){
        res[1] = res[0];
        ++i_start;
    }
    resu = kj_charcut_str(res, i_start, res_size, res_size + 1);
    free(res);
    return (resu);
}

char *kj_getfloat(double nb, int virg)
{
    linked_list_t *result = NULL;
    char *res;
    int res_size;

    if (nb > 1.7976931348623157e+308 ||
    nb < -1.7976931348623157e+308)
        return (my_strdup("inf"));
    if (nb < 0){
        nb *= -1;
        kj_put_in_chain(&result, "-");
    }
    if (virg > 9)
        virg = 9;
    kj_insert_float(&result, nb, virg + 1);
    my_rev_list(&result);
    res = kj_chain_to_str(result);
    kj_free_list(result);
    res_size = my_strlen(res) - 2;
    do_round_sup(res, res_size, res_size, 0);
    return (kj_putfloat_print(res, res_size));
}
