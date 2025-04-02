/*
** EPITECH PROJECT, 2023
** Rush 1 ASS1
** File description:
** write different square
*/

int rush(int x, int y)
{
    write_first_last(x);
    if (y > 2) {
        ligne(x, y - 2);
    }
    if (y > 1) {
        write_first_last(x);
    }
}

int write_last_char(int dernier_caractere, int x)
{
    if (dernier_caractere == 2 || x == 1) {
        my_putchar('\n');
    }
}

int write_first_last(int x)
{
    int compteur = x;
    int dernier_caractere;

    for (; compteur != 0; compteur --) {
        if (compteur == x || compteur - 1 == 0) {
            my_putchar('o');
            dernier_caractere ++;
            write_last_char(dernier_caractere, x);
        } else {
            my_putchar('-');
        }
    }
}

int colone(int b, int a)
{
    for (b ; b > 0 ; b --) {
        my_putchar('|');
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
            my_putchar('|');
            colone(0, col);
            my_putchar('|');
            my_putchar('\n');
        }
    }
}
