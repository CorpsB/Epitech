/*
** EPITECH PROJECT, 2023
** LOAD
** File description:
** Project load file.
*/

#include "../../include/project.h"

static int is_assign_id(champions_t *champion, int id)
{
    if (champion == NULL)
        return 1;
    for (champions_t *tmp = champion; tmp != NULL; tmp = tmp->next)
        if (tmp->id == id)
            return 0;
    return 1;
}

static int get_champion_id(corewar_t *vm, int arg_n)
{
    int select_id = (arg_n == -1) ? vm->count : arg_n;

    while (is_assign_id(vm->champions->next, select_id) != 1)
        ++select_id;
    ++vm->count;
    return select_id;
}

static int assign_data(char **av, int ac, int i, int *stock)
{
    if (i + 1 >= ac || secure_getnbr(stock, av[i + 1]))
        *stock = -2;
    return 1;
}

int load_argument(champion_shema_t **id, int ac, char **av, int *i)
{
    int arg_a = -1;
    int arg_n = -1;
    int cpt = 0;

    for (; *i < ac; *i += 2){
        if (my_strcmp(av[*i], "-a") == 0)
            cpt += assign_data(av, ac, *i, &arg_a);
        if (my_strcmp(av[*i], "-n") == 0)
            cpt += assign_data(av, ac, *i, &arg_n);
        if (arg_a == -2 || arg_n == -2)
            return 1;
        if (arg_a == -1 && arg_n == -1 && av[*i][0] == '-')
            return 1;
        if (cpt == 0){
            l_add_shema(id, arg_a, arg_n, av[*i]);
            break;
        }
        cpt = 0;
    }
    return 0;
}

int load_champion(corewar_t *vm, champion_shema_t *shema, int nb, int i)
{
    int fd = open(shema->path, O_RDONLY, 0666);

    if (fd == -1 || verify_magic(fd))
        return 1;
    l_add_champion(&vm->champions);
    init_champion(vm->champions);
    if (verify_header(fd, vm->champions))
        return 1;
    vm->champions->pc = (shema->arg_a == -1) ?
    (MEM_SIZE * 2) / nb * i : shema->arg_a * 2;
    vm->champions->map_id = vm->count;
    vm->champions->id = get_champion_id(vm, shema->arg_n);
    put_register(1, vm->champions->id, vm->champions);
    store_data(fd, vm, shema);
    close(fd);
    return 0;
}

int load_shema(corewar_t *vm, champion_shema_t *shema)
{
    int nb_shema = l_size_shema(&shema);
    int i = 0;

    if (nb_shema < 2)
        return 1;
    l_reverse_shema(&shema);
    for (champion_shema_t *tmp = shema; tmp != NULL; tmp = tmp->next){
        if (load_champion(vm, tmp, nb_shema, i)){
            l_free_shema(&shema);
            return 1;
        }
        ++i;
    }
    l_free_shema(&shema);
    return 0;
}
