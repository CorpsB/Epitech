/*
** EPITECH PROJECT, 2023
** KJ_CHAIN_TO_STR
** File description:
** Return an char build from an linkedlist.
*/

#include "../../includes/my.h"

char *kj_chain_to_str(linked_list_t *list)
{
    int size = my_list_size(list);
    char *str = malloc((sizeof(char) * size) + 1);
    linked_list_t *tmp = list;
    int i = 0;
    char *num;

    while (tmp != NULL){
        num = tmp->data;
        str[i] = num[0];
        ++i;
        tmp = tmp->next;
    }
    str[i] = '\0';
    return (str);
}
