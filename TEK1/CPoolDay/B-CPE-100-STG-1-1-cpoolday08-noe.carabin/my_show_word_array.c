/*
** EPITECH PROJECT, 2023
** MY_SHOW_WORD_ARRAY
** File description:
** show param
*/

char my_show_word_array(char const **tab)
{
    int compteur = 0;

    for (;tab[compteur] != 0; compteur++) {
        my_putstr(tab[compteur]);
        my_putchar('\n');
    }
}
