/*
** EPITECH PROJECT, 2023
** rush 1.2
** File description:
** write a square with different car (and anormal)
*/

int write_normal(x, y)
{
    int slash = 47;
    int temp;
    int b_slash = 92;

    write_first_last(x, slash, b_slash);
    if (y > 2) {
        ligne(x, y - 2);
    }
    temp = slash;
    slash = b_slash;
    b_slash = temp;
    if (y > 1) {
        write_first_last(x, slash, b_slash);
    }
}

int write_exeption(x, y)
{
    int compteur;

    if (x == 1) {
        for (; y > 0 ; y--) {
            my_putchar('*');
            my_putchar('\n');
        }
    } else {
        for (; x > 0 ; x--) {
            my_putchar('*');
        }
        my_putchar('\n');
    }
}
