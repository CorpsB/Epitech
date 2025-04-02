/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_list_size.c
*/

#include "../my.h"

/***
 * Renvoie la taille de la liste.
*/
int my_list_size(linked_t *begin)
{
    int cpt = 0;
    linked_t *tmp = begin;

    for (; tmp != NULL; cpt++) {
        tmp = tmp->next;
    }
    return (cpt);
}
