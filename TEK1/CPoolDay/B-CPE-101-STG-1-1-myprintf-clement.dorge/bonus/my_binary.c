/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a long
*/

#include<stdio.h>
#include <stddef.h>

int **my_calc_bin(int a, int i, int ***result)
{
    if (a < 0)
        a = -a;
    if (a > 1)
        my_calc_bin(a / 2, i + 1, result);
    result[i] = (a % 2 + 48);
    return result;
}

void my_rev_bin(int ***b, int limit, int z)
{
    int retained = 1;

    for (int i = 0; i < limit; i++) {
        if (b[i] == 49) {
            b[i] = 48;
            continue;
        }
        if (b[i] == 48)
            b[i] = 49;
    }
    while (b[limit - z] != 49)
        z++;
    for (int i = 0; i < z + 1; i++) {
        if (b[i] == 48) {
            b[i] = 49;
            break;
        }
        if (b[i] == 49)
            b[i] = 48;
    }
}

void my_binary(int a)
{
    int **result[34] = {'\0'};
    int limit = 0;
    int tmp;

    my_calc_bin(a, 0, &result);
    if (result[0] == '\0')
        return;
    for (int i = 0; result[i] != '\0'; i++)
        limit++;
    tmp = limit;
    if (a < 0) {
        my_rev_bin(&result, limit, 0);
        while (tmp != 32) {
            tmp += 1;
            my_putchar('1');
        }
        limit -= 1;
    }
    for (int i = limit; i >= 0; i--)
        my_putchar(result[i]);
}
