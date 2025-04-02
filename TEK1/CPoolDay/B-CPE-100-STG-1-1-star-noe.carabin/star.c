/*
** EPITECH PROJECT, 2023
** STAR
** File description:
** write star with different size.
*/

void star(int size)
{
    int universal_space = 0;

    if (size > 1) {
        universal_space = star_top(size);
        star_line(size, universal_space);
        star_bbody(size, universal_space, star_tbody(size, universal_space));
        star_line(size, universal_space);
        star_bottom(size, universal_space);
    } else if (size == 1) {
        star_one();
    }
}

int star_top(int size)
{
    int compteur = 0;
    int space_center = 3 * size - 2;

    space(3 * size - 1);
    my_putchar('*');
    my_putchar('\n');
    compteur ++;
    for (; compteur < size ; compteur ++) {
        space(space_center);
        space_center --;
        my_putchar('*');
        space(2 * compteur - 1);
        my_putchar('*');
        my_putchar('\n');
    }
    return (space_center);
}

int star_line(int size, int universal_space)
{
    int compteur = 0;

    for (;compteur <= universal_space + 1; compteur ++) {
        my_putchar('*');
            }
    space(size * 2 - 3);
    compteur = 0;
    for (;compteur <= universal_space + 1; compteur ++) {
        my_putchar('*');
            }
    my_putchar('\n');
}

int star_tbody(int size, int universal_space)
{
    int compteur = 1;
    int space_center = (2 * universal_space + 2 + 2 * size - 1) - 4;
    int compteur_center = 1;

    for (;compteur <= size ; compteur ++) {
        space(compteur);
        my_putchar('*');
        space(space_center);
        space_center = space_center - 2;
        my_putchar('*');
        my_putchar('\n');
                }
    return (space_center);
}

int star_bbody(int size, int universal_space, int space_center)
{
    int compteur = size - 1;

    space_center = space_center + 2;
    for (;compteur != 0 ; compteur --) {
        space(compteur);
        my_putchar('*');
        space_center = space_center + 2;
        space(space_center);
        my_putchar('*');
        my_putchar('\n');
                }
}
