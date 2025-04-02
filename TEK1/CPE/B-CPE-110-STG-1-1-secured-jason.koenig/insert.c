/*
** EPITECH PROJECT, 2023
** Secured
** File description:
** insert.c
*/

#include "include/hashtable.h"
#include "include/my.h"
#include <stdbool.h>

void my_put_in_list(dlist **list, char *comment, int key)
{
    dlist *tmp;

    tmp = malloc(sizeof(dlist));
    tmp->comment = my_strdup(comment);
    tmp->hash = key;
    tmp->next = *list;
    *list = tmp;
}

bool static colision_checker(int nbr, int index, hashtable_t *ht, char *com)
{
    dlist *tmp = ht[index].table;

    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->hash == nbr){
            free(tmp->comment);
            tmp->comment = my_strdup(com);
            return (true);
        }
    return (false);
}

void static insert(hashtable_t *ht, char *key, char *comment)
{
    int hash_value = ht->hash(key, 0);
    int index = hash_value % ht->size;
    bool colision = colision_checker(hash_value, index, ht, comment);

    if (colision)
        return;
    my_put_in_list(&(ht[index].table), comment, hash_value);
}

int ht_insert(hashtable_t *ht, char *key, char *comment)
{
    if (ht == NULL || comment == NULL || key == NULL)
        return (84);
    if (ht->size < 1)
        return (84);
    insert(ht, key, comment);
    return (0);
}
