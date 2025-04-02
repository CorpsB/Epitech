/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../include/project.h"

int help_function(void)
{
    int nbr = open("./src/help/help.txt", O_RDONLY);
    struct stat information;
    char *message;

    stat("./src/help/help.txt", &information);
    message = malloc(sizeof(char) * (information.st_size + 1));
    read(nbr, message, information.st_size);
    write(1, message, information.st_size);
    close(nbr);
    free(message);
    return 0;
}

int msg(int exit_code, int port, int nb, ...)
{
    va_list list;

    va_start(list, nb);
    for (int i = 0; i < nb; ++i)
        my_putstr(va_arg(list, char *), port);
    va_end(list);
    return exit_code;
}

int main(int ac, char **av)
{
    champion_shema_t *id = NULL;
    corewar_t vm;
    int i = 1;

    init_vm(&vm);
    if (ac == 1)
        return msg(84, 2, 1, "INIT: To few warrior\n");
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return help_function();
    if (my_strcmp(av[1], "-dump") == 0 && ac > 2)
        if (secure_getnbr(&vm.dump_freq, av[2]))
            return msg(84, 2, 1, "INIT: header error\n");
    if (vm.dump_freq != -1)
        i = 3;
    for (; i < ac; ++i)
        if (load_argument(&id, ac, av, &i))
            return msg(84, 2, 1, "INIT: header error\n");
    if (load_shema(&vm, id))
        return msg(84, 2, 1, "INIT: To few warrior\n");
    return exec_vm(&vm);
}
