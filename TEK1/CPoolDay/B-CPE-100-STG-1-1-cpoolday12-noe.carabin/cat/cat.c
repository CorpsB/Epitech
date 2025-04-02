/*
** EPITECH PROJECT, 2023
** cat
** File description:
** reproduce the cat command
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    if (ac == 1) {
        cat_anormal();
    } else {
        for (int cpt = 1; cpt < ac; cpt ++) {
            normal_cat(av[cpt]);
                }
    }
}

int normal_cat(char *av)
{
    int open_result;
    char buffer [1001];
    int read_result = 1;

    open_result = open(av, O_RDONLY);
    if (open_result < 0) {
        my_putstr("cat: ");
        my_putstr(av);
        my_putstr(": No such file or directory");
        my_putchar('\n');
        return (84);
    }
    for (; read_result != 0;) {
        read_result = read(open_result, buffer, 1000);
        write(1, buffer, read_result);
    }
    close(open_result);
}

int cat_anormal(void)
{
    int read_result = 1;
    char buffer[1001];

    for (; read_result != 0;) {
        read_result = read(0, buffer, 1000);
        write(1, buffer, read_result);
    }
}
