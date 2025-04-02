/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "include/my.h"
#include "include/hashtable.h"

// fnv1a_hash
int hash(char *key, int len)
{
    unsigned int hash = 2166136261;

    for (int i = 0; key[i] != '\0'; ++i)
        hash = (hash ^ key[i]) * 16777619;
    return hash % 2147483648;
}
