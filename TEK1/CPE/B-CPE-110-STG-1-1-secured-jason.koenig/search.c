/*
** EPITECH PROJECT, 2023
** Secured
** File description:
** search.c
*/

#include "include/hashtable.h"
#include "include/my.h"

char *search(hashtable_t *ht, char *key)
{
    int hash_value = ht->hash(key, 0);
    int index = hash_value % ht->size;
    dlist *tmp = ht[index].table;

    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->hash == hash_value)
            return (tmp->comment);
    return (NULL);
}

//Regarder pour chercher quelque chose qui ne se trouve pas
char *ht_search(hashtable_t *ht, char *key)
{
    if (ht == NULL || key == NULL)
        return (NULL);
    if (ht->size < 1)
        return (NULL);
    return (search(ht, key));
}
