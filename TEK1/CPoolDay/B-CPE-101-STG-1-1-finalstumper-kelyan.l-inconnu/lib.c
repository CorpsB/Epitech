/*
** EPITECH PROJECT, 2023
** Different fonction
** File description:
** Different founction, that use
*/

int my_putchar(char *c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    long n;
    char temp;

    n = nb;
    if (n < 0) {
        n *= -1;
        write(1, '-', 1);
    }
    if (n) {
        if (n / 10)
            my_put_nbr(n / 10);
            temp = 48 + (n % 10);
            write(1, &temp, 1);
    }
    if (n == 0) {
        write(1, '0', 1);
    }
}
