/*
** EPITECH PROJECT, 2023
** mini printf
** File description:
** print a string
*/

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0' ; i = i + 1) {
            my_putchar(str[i]);
                }
}

int mini_s(char *str)
{
    my_putstr(str);
}
