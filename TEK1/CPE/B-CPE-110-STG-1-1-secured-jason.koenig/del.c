/*
** EPITECH PROJECT, 2023
** Secured
** File description:
** del.c
*/

#include "include/hashtable.h"
#include "include/my.h"

static int del_node(dlist *prv)
{
    free(prv->comment);
    free(prv);
    return (0);
}

void delete_first(dlist *tmp, dlist *prv, dlist **list)
{
    prv = tmp;
    tmp = tmp->next;
    del_node(prv);
    *list = tmp;
}

int del_in_list(dlist **list, int hash)
{
    dlist *prv = NULL;
    dlist *tmp = *list;

    if (tmp->hash == hash) {
        delete_first(tmp, prv, list);
        return (0);
    }
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->hash == hash) {
            prv->next = tmp->next;
            return del_node(tmp);
        }
        prv = tmp;
    }
    return (84);
}

int del(hashtable_t *ht, char *key)
{
    int hash_value = ht->hash(key, 0);
    int index = hash_value % ht->size;

    return del_in_list(&(ht[index].table), hash_value);
}

int ht_delete(hashtable_t *ht, char *key)
{
    if (ht == NULL || key == NULL)
        return (84);
    if (ht->size < 1)
        return (84);
    return del(ht, key);
}
