/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** my_strstr
*/

#include "../../includes/my.h"

char *my_strstr(char *str, char const *to_find)
{
    const char *str_ = str;
    const char *to_find_ = to_find;

    if (*to_find == '\0'){
        return str;
    }
    while (*str != '\0'){
        while (*to_find_ != '\0' && *str_ == *to_find_){
            str_++;
            to_find_++;
        }
        if (*to_find_ == '\0'){
            return str;
        }
        str++;
    }
    return NULL;
}
