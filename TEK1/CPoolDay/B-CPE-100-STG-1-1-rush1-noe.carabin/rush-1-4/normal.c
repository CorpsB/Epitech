/*
** EPITECH PROJECT, 2023
** rush 1.2
** File description:
** write a square with different car
*/

int rush(int x, int y)
{
    if (x == 1 || y == 1) {
        write_exeption(x, y);
    } else {
        write_normal(x, y);
    }
}

int write_first_last(int x, int slash, int b_slash)
{
    int compteur = 0;

    for (; compteur < x - 1; compteur ++) {
        if (compteur == 0) {
            my_putchar(slash);
            put_space(x - 2);
            my_putchar(b_slash);
            my_putchar('\n');
        }
    }
}

int colone(int b, int a)
{
    for (b ; b > 0 ; b --) {
        my_putchar('B');
        my_putchar('\n');
    }
    for (int i = a - 2 ; i > 0 && b == 0 ; i--) {
        my_putchar(' ');
    }
}

int ligne(int col, int lig)
{
    if (col == 1) {
        colone(lig, 0);
    } else {
        for (lig; lig > 0 ; lig--) {
            my_putchar('B');
            colone(0, col);
            my_putchar('B');
            my_putchar('\n');
        }
    }
}

int put_space(x)
{
    int compteur = 0;

    for (; compteur < x; compteur++) {
        my_putchar('B');
    }
}
