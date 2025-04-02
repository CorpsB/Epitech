/*
** EPITECH PROJECT, 2023
** rush 1 step 1
** File description:
** search letter ocurence
*/

int counting_letter(int comparator, char **av)
{
    int nb = result(comparator, av);
    int nbTT = size(av);

    my_putchar(av[comparator][0]);
    my_putchar(':');
    my_put_nbr(nb);
    my_putchar(' ');
    my_putchar('(');
    my_put_float(nb, nbTT);
    my_putchar(')');
    my_putchar('\n');
}

int maj_test(int comparator, char **av)
{
    int maj = 32;

    if (av[comparator][0] < 'z' && av[comparator][0] > 'a') {
        maj = maj * (-1);
    }
    return (maj);
}

int result(int comparator, char **av)
{
    int letter = 0;
    int maj = maj_test(comparator, av);

    for (int cpt = 0; av[1][cpt] != '\0'; cpt++)
        if (av[1][cpt] == av[comparator][0] ||
            av[1][cpt] == (av[comparator][0] + maj)) {
            letter++;
        }
    return (letter);
}

int my_put_float(int nb, int nbTT)
{
    int i = 0;
    int k = 0;
    int j = 0;

    i = ((float)nb / (float)nbTT) * 100;
    j = ((float)nb / (float)nbTT) * 100 * 100;
    k = j - (i * 100);
    my_put_nbr(i);
    my_putchar('.');
    my_put_nbr(k);
    my_putchar('%');
}

static int size(char **av)
{
    int i = 1;

    for (int cpt = 0; av[1][cpt] != '\0'; cpt++) {
        if (av[1][cpt] < 'z' && av[1][cpt] > 'a' ||
            av[1][cpt] < 'Z' && av[1][cpt] > 'A') {
            i++;
                }
    }
    return (i);
}

static int error_test(char **av, int error)
{
    if (av[2][0] == 'NULL' || av[3][0] == 'NULL') {
        error = 84;
    }
}

int main(int ac, char **av)
{
    int *error = 0;

    error_test(av, &error);
    for (int comparator = 2; comparator < ac; comparator++) {
        counting_letter(comparator, av);
    }
    return (error);
}
