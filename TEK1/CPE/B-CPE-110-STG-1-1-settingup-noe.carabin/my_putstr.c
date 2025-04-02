/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** write one by one a caracter sting
*/

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0' ; i = i + 1) {
        my_putchar(str[i]);
    }
}
