/*
** EPITECH PROJECT, 2023
** MY_STRNCPY
** File description:
** Exchange two string with a limit (n).
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int compteur = 0;

    for (;compteur < n; compteur++) {
        dest[compteur] = src[compteur];
    }
    for (;compteur < n; compteur ++) {
        dest[compteur] = '\0';
            }
    return (dest);
}
