/*
** EPITECH PROJECT, 2023
** B-CPE-210-STG-2-1-solostumper05-thibaut.louis
** File description:
** my_strlowcas.c
*/

#include "../../my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
    return str;
}
