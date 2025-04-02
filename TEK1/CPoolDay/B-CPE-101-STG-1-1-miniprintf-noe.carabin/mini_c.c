/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a char
*/

int my_putchar(char c)
{
    write(1, &c, 1);
}

int mini_c(char a)
{
    my_putchar(a);
}
