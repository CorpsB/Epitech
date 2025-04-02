/*
** EPITECH PROJECT, 2023
** lib
** File description:
** del_in_list.c
*/

#include "../my.h"

// static int del_node(linked_t *prv)
// {
//     free(prv->line);
//     free(prv);
//     return 0;
// }

// void delete_first(linked_t *tmp, linked_t *prv, linked_t **list)
// {
//     prv = tmp;
//     tmp = tmp->next;
//     del_node(prv);
//     *list = tmp;
// }

/**
 * Cette fonction supprime et free le maillon de la chaine à supprimer. Return
 * 0 si elle trouve le maillon, sinon, 84.
*/
// int del_in_list(linked_t **list, int nbr)
// {
//     linked_t *prv = NULL;
//     linked_t *tmp = *list;

//     if (tmp->id == nbr) {
//         delete_first(tmp, prv, list);
//         return 0;
//     }
//     while (tmp != NULL) {
//         if (tmp->id != nbr) {
//             prv = tmp;
//             tmp = tmp->next;
//             continue;
//         }
//         prv->next = tmp->next;
//         return del_node(tmp);
//     }
//     return 84;
// }
