/*
** EPITECH PROJECT, 2023
** rush 1.2
** File description:
** write a square with different car (and anormal)
*/

int write_normal(x, y)
{
    int slash = 65;

    write_first_last(x, slash);
    if (y > 2) {
        ligne(x, y - 2);
    }
    slash = 67;
    if (y > 1) {
        write_first_last(x, slash);
    }
}

int write_exeption(x, y)
{
    int compteur;

    if (x == 1) {
        for (; y > 0 ; y--) {
            my_putchar('B');
            my_putchar('\n');
        }
    } else {
        for (; x > 0 ; x--) {
            my_putchar('B');
        }
        my_putchar('\n');
    }
}
