/*
** EPITECH PROJECT, 2023
** MY_REVSTR
** File description:
** Reverse a string
*/

int my_strlen(char const *str)
{
    int i = 0;
    int char_number = 0;

    for (; str[i] != '\0' ; i = i + 1) {
        char_number = char_number + 1;
    }
    return (char_number);
}

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
