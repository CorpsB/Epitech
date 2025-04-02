/*
** EPITECH PROJECT, 2023
** MY_REVSTR
** File description:
** Reverse a string
*/

char *my_revstr(char *str)
{
    int compteur = 0;
    int str_len = my_strlen(str);
    int decompteur = my_strlen(str) - 1;
    char temp;

    for (; compteur != (str_len / 2); compteur++) {
        temp = str[compteur];
        str[compteur] = str[decompteur];
        str[decompteur] = temp;
        decompteur--;
    }
    return (str);
}
