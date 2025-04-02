/*
** EPITECH PROJECT, 2023
** STAR2
** File description:
** The last fonction that i use to pint a stair.
*/

int star_one(void)
{
    space(3);
    my_putchar('*');
    my_putchar('\n');
    put_star(3);
    space(1);
    put_star(3);
    my_putchar('\n');
    space(1);
    my_putchar('*');
    space(3);
    my_putchar('*');
    my_putchar('\n');
    put_star(3);
    space(1);
    put_star(3);
    my_putchar('\n');
    space(3);
    my_putchar('*');
    my_putchar('\n');
}

int put_star(int nbr)
{
    int compteur = 0;

    for (; compteur < nbr ; compteur ++) {
    my_putchar('*');
    }
}

int space(int nbr)
{
    int compteur = 0;

    for (; compteur < nbr ; compteur ++) {
        my_putchar(' ');
    }
}

int star_bottom(int size, int universal_space)
{
    int decompteur = size;
    int decr_space = 0;
    int incr_space = 0;

    for (;decompteur != 1; decompteur --) {
        space(universal_space + 1 + incr_space);
        incr_space ++;
        my_putchar('*');
        space(2 * size -3 + decr_space);
        decr_space = decr_space - 2;
        my_putchar('*');
        my_putchar('\n');
    }
    space(3 * size - 1);
    my_putchar('*');
    my_putchar('\n');
}
