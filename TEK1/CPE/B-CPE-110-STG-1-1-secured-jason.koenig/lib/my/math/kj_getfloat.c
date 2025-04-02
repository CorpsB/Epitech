/*
** EPITECH PROJECT, 2023
** KJ_GETFLOAT
** File description:
** Tranform a float number into a string.
*/

#include "../../../include/my.h"
static char *kj_subzero_to_str(char *result, int i, int virg)
{
    char carac[] = "#";
    int i_max = my_strlen(result) - 1;

    for (; i < virg + 1; ++i){
        carac[0] = '0';
        result = my_strcat(result, carac);
    }
    return (result);
}

static char *kj_insert_float(char *result, double nb, int virg)
{
    unsigned long long num = (unsigned long long)(nb / 1);
    unsigned long long num2;
    char *str_num = kj_int_to_str(num);
    int i;

    nb -= ((unsigned long long)(nb / 1));
    nb *= kj_xposant(10, virg);
    num2 = (unsigned long long)(nb / 1);
    result = my_strcat(result, "0");
    result = my_strcat(result, str_num);
    result = my_strcat(result, ".");
    free(str_num);
    str_num = kj_int_to_str(num2);
    result = my_strcat(result, str_num);
    result = kj_subzero_to_str(result, my_strlen(str_num) - 1, virg);
    free(str_num);
    return (result);
}

static char *do_round_sup(char *str, int i, int i_max, int reste)
{
    if (str[i] == '.')
        --i;
    if (str[i] + reste > '9' || (i == i_max - 1 && str[i] >= '5')){
        str[i] = '0';
        reste = 1;
        do_round_sup(str, i - 1, i_max, reste);
    } else {
        str[i] += reste;
    }
    return (str);
}

static char *kj_putfloat_print(char *res, int res_size)
{
    char *result;
    int i_start = 0;

    if (res[0] == '0')
        ++i_start;
    if (res[0] == '-' && res[1] == '0'){
        res[1] = res[0];
        ++i_start;
    }
    if (res[res_size - 2] == '.')
        res_size -= 1;
    result = my_substr(res, i_start, res_size - 1);
    free(res);
    return (result);
}

char *kj_getfloat(double nb, int virg)
{
    char *result = my_strdup("");
    int res_size;

    if (nb > 1.7976931348623157e+308 ||
    nb < -1.7976931348623157e+308)
        return (my_strdup("inf"));
    if (nb < 0){
        nb *= -1;
        result = my_strcat(result, "-");
    }
    if (virg > 9)
        virg = 9;
    result = kj_insert_float(result, nb, virg + 1);
    res_size = my_strlen(result) - 2;
    result = do_round_sup(result, res_size - 1, res_size, 0);
    return (kj_putfloat_print(result, res_size));
}
