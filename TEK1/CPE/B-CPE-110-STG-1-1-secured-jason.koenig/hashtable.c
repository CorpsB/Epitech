/*
** EPITECH PROJECT, 2024
** HASHTABLE HANDLER
** File description:
** Hashtable things.
*/

#include "include/my.h"
#include "include/hashtable.h"

//Ajouter une gestion d'erreur si args == NULL
hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hasht;

    if (len < 0 || hash == NULL)
        return NULL;
    hasht = malloc(sizeof(struct hashtable_s) * len);
    for (int i = 0; i < len; ++i)
        hasht[i].table = NULL;
    hasht->size = len;
    hasht->hash = hash;
    return (hasht);
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int i = ht->size - 1; i > -1; --i)
        kj_free_dlist(&ht[i].table);
    free(ht);
}

void ht_dump(hashtable_t *ht)
{
    dlist *list;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->size; ++i){
        my_putchar('[');
        my_putnbr(i);
        my_putstr("]:\n");
        for (list = ht[i].table; list != NULL; list = list->next){
            my_putstr("> ");
            my_putnbr(list->hash);
            my_putstr(" - ");
            my_putstr(list->comment);
            my_putchar('\n');
        }
    }
}
