/*
** EPITECH PROJECT, 2023
** Reverse alphabet
** File description:
** write reverse alphabet
*/

int my_print_revalpha(void)
{
    for (int nb = 'z'; nb >= 'a'; nb = nb - 1 ) {
        my_putchar(nb);
    }
    return 0;
}
