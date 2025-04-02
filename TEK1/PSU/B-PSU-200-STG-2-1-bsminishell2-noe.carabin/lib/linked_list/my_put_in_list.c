/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_put_in_list.c
*/

#include "../my.h"

/***
 * Renvoie le nombre d'éléments dans la liste.
*/
int my_put_in_list(linked_t **list, int instructions, int size)
{
    linked_t *element;

    element = malloc(sizeof(*element));
    element->instructions = instructions;
    element->size = size;
    element->id = my_list_size(*list) + 1;
    element->next = *list;
    *list = element;
    return (0);
}
