/*
** EPITECH PROJECT, 2023
** my strcat
** File description:
** Two string together
*/

char *my_strcat(char *dest, char const *src)
{
    int compteur = 0;
    int src_compteur = 0;

    for (; dest[compteur] != '\0'; compteur ++) {
    }
    for (; src[src_compteur] != '\0'; compteur ++) {
        dest[compteur] = src[src_compteur];
        src_compteur ++;
    }
    return (dest);
}
