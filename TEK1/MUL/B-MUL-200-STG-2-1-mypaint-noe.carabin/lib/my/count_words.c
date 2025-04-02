/*
** EPITECH PROJECT, 2024
** My Library (Epitech)
** File description:
** count_words
*/

#include "../../includes/my.h"

int count_words(char *str)
{
    int count = 0;
    int is_word = 0;

    for (int i = 0; str[i] != '\0'; i++){
        while (str[i] == ' '){
            is_word = 0;
            i++;
        }
        if (str[i] != '\0' && is_word == 0){
            count++;
            is_word = 1;
        }
    }
    return count;
}
