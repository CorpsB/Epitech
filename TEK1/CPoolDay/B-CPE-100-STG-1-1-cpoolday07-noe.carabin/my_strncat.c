/*
** EPITECH PROJECT, 2023
** MY_STRNCAT
** File description:
** write dest and n src char
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int compteur_dest = 0;
    int src_compteur = 0;
    int compteur = 0;

    if (nb < 0) {
        return;
    }
    for (; dest[compteur_dest] != '\0'; compteur_dest ++) {
    }
    for (; compteur <= nb ; compteur ++) {
        dest[compteur_dest] = src[src_compteur];
        src_compteur ++;
        compteur_dest++;
    }
    return (dest);
}
