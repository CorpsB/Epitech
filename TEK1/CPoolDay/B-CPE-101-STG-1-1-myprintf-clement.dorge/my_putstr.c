/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a string
*/

#include <stddef.h>

static int my_strlen(char const *str)
{
    int i = 0;
    int char_number = 0;

    for (; str[i] != '\0' ; i = i + 1) {
        char_number = char_number + 1;
    }
    return (char_number);
}

int stmy_putstr(char const *str, int precision)
{
    int i = 0;

    for (; str[i] != '\0'; i = i + 1) {
        if (precision != NULL && i >= precision) {
            return (i + 1);
        }
            my_putchar(str[i]);
                }
    return (i + 1);
}

int my_putstr(char const *str, char *forme, int largeur, int precision)
{
    int i = 0;

    if (precision == NULL) {
        i = my_strlen(str);
    } else {
        i = precision;
    }
    if (largeur != NULL && (forme[0] != '-' && forme[1] != '-')) {
        for (int cpt = 0; cpt < largeur - i; cpt++){
            my_putchar(' ');
        }
    }
    stmy_putstr(str, precision);
    if ((forme[0] == '-' || forme[1] == '-') && largeur != NULL) {
        for (int cpt = 0; cpt + i < largeur; cpt ++)
        my_putchar(' ');
    }
}
