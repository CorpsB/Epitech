/*
** EPITECH PROJECT, 2023
** CPE
** File description:
** tools.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    int char_number = 0;

    for (; str[i] != '\0'; i = i + 1) {
        char_number = char_number + 1;
    }
    return (char_number);
}

int my_strcompare(char *first, char *second)
{
    if (my_strlen(first) != my_strlen(second)) {
        return 0;
    }
    for (int i = 0; first[i] != '\0'; i++) {
        if (first[i] != second[i]) {
            return 0;
        }
    }
    return 1;
}

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        my_putchar(str[i]);
    }
}

int my_putnbr(int a)
{
    int b = a;
    int cpt = 0;

    if (b < 0) {
        my_putchar(45);
        a = a * (-1);
    }
    if (a > 9) {
        my_putnbr(a / 10);
    }
    my_putchar(a % 10 + 48);
}
