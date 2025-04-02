/*
** EPITECH PROJECT, 2023
** Test revstr
** File description:
** test my_revstr
*/

#include <criterion/criterion.h>

Test (my_revstr, reverse_string)
{
    char *str = strdup("Hello\0");
    char *res = strdup ("olleH\0");
    char *truc = my_revstr(str);

    cr_assert_str_eq(truc, res);
}
