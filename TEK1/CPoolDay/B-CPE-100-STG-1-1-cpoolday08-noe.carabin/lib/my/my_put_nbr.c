/*
** EPITECH PROJECT, 2023
** Put number
** File description:
** Write a number (lmimit = int)
*/

int my_put_nbr(int a)
{
    int b = a;

    if (a == 0) {
        my_putchar(48);
        return (0);
            }
    if (b < 0) {
            my_putchar(45);
            a = a*(-1);
        }
    my_put_nbr(a / 10);
    my_putchar(a % 10 + 48);
}
