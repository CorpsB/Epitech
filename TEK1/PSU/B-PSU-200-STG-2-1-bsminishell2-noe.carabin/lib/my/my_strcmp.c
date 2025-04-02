/*
** EPITECH PROJECT, 2023
** STRCMP
** File description:
** A function that return 0 if it's false, and 1 if it's true
*/

#include "../my.h"

/**
 * Cette fonction compare deux string et renvoie true si elles sont identiques,
 * false dans le cas contraire.
*/
bool my_strcmp(char *first, char *second)
{
    if (my_strlen(first) != my_strlen(second)) {
        return false;
    }
    for (int i = 0; first[i] != '\0'; i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}
