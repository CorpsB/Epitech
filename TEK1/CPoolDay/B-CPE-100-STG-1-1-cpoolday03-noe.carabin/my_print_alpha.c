/*
** EPITECH PROJECT, 2023
** my_print_alpha.c
** File description:
** Write alphabet
*/

int my_print_alpha(void)
{
    for (int nb = 'a'; nb <= 'z'; nb++ ) {
        my_putchar(nb);
    }
    return 0;
}
