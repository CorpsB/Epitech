/*
** EPITECH PROJECT, 2023
** KJ_COUNT_NUMBER
** File description:
** Return the size of an integer.
*/

#include "../../../include/my.h"
int kj_count_number(unsigned long long n)
{
    int c = 1;

    for (; (n / 10) >= 1; ++c)
        n /= 10;
    return (c);
}
