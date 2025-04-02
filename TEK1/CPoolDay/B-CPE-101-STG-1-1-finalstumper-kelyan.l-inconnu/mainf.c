/*
** EPITECH PROJECT, 2023
** Final stumper
** File description:
** Return the type of the rush1 and the size.
*/

static int size1(char *str)
{
    int cpt1 = 1;
    int cpt2 = 0;

    for (; cpt2 < 2 ; cpt1++) {
        if (str[cpt1] != str[1]) {
            cpt2++;
        }
    }
    return (cpt1 + 1);
}

static int size2(char *str, int cpt)
{
    int cpt2 = 0;
    int cpt1 = 0;

    for (; cpt2 < 4; cpt1++) {
        if (str[cpt1] == 'o' || str[cpt1] == 'A' || str[cpt1] == 'C' ||
            str[cpt1] == '/' || str[cpt1] == 92) {
            cpt2++;
        }
    }
    return (cpt1 / cpt);
}

char nbr_l(char *str, int cpt1, int cpt2)
{
    int cpt4 = 0;

    for (; str[cpt4 + 2] != '\0'; cpt4++) {
        }
    return (str[cpt4]);
}

int selector(char j, char l)
{
    if (j == 'A') {
        my_putstr("[rush1-3]");
        return 0;
    }
    if (l == 'C') {
        my_putstr("[rush1-4]");
        return 0;
    } else {
        my_putstr("[rush1-5]");
        return 0;
    }
}

static int grand_switch(char i, char j, char l)
{
    switch (i) {
    case 'o':
        my_putstr("[rush1-1]");
        break;
    case '/' :
        my_putstr("[rush1-2]");
        break;
    default:
        selector(j, l);
        break;
    }
}

int select( char *str, int cpt1, int cpt2)
{
    char i = str[0];
    char j = str[cpt1 - 1];
    char l = nbr_l(str, cpt1, cpt2);

    grand_switch(i, j, l);
}

int princip(char *str)
{
    int cpt1 = size1(str);
    int cpt2 = size2(str, cpt1);

    if (cpt1 == 1 && cpt2 == 1) {
        return (0);
    }
    select(str, cpt1, cpt2);
    my_putchar(' ');
    my_put_nbr(cpt1);
    my_putchar(' ');
    my_put_nbr(cpt2);
    my_putchar('\n');
}

int main(int ac, char **av)
{
    if (av[0] == 'NULL') {
        my_putstr("none");
        return 0;
    }
    princip(av[0]);
}
