/*
** EPITECH PROJECT, 2023
** EXEC
** File description:
** Project exec file.
*/

#include "../include/project.h"
#include "graphical.h"

void exec_champion(corewar_t *vm, champions_t *champion)
{
    char *action = &vm->memory[champion->pc];

    exec_function_selector(vm, champion, action);
    ++champion->cycle_life;
    if (champion->cycle_life == vm->cycle_die)
        champion->is_alive = false;
    if (vm->nb_live >= NBR_LIVE){
        vm->nb_live = 0;
        vm->cycle_die -= CYCLE_DELTA;
    }
}

static int check_vitals(int vitals)
{
    int cpt = 0;
    char *vitals_char = s_convert_n(vitals);

    if (vitals_char[3] != '2')
        ++cpt;
    if (vitals_char[2] != '2')
        ++cpt;
    if (vitals_char[1] != '2')
        ++cpt;
    if (vitals_char[0] != '2')
        ++cpt;
    free(vitals_char);
    if (cpt > 1)
        return 1;
    return 0;
}

int exec_vm_cycle(corewar_t *vm, int cycle, WINDOW *win, char ***title)
{
    vm->vitals = 2222;
    for (champions_t *tmp = vm->champions; tmp != NULL; tmp = tmp->next){
        if (tmp->is_alive == true && tmp->pc < MEM_SIZE * 2){
            exec_champion(vm, tmp);
            vm->vitals += n_power(10, tmp->map_id - 1);
        }
    }
    graphical(vm, cycle, win, title);
    if (check_vitals(vm->vitals))
        return 1;
    return 0;
}

static char ***init_screen(WINDOW **win)
{
    char ***title = NULL;

    initscr();
    title = init_title();
    *win = newwin(80, LCHAR * 1.5 - 1, 0, 0);
    box(*win, 0, 0);
    curs_set(0);
    return title;
}

int exec_vm(corewar_t *vm)
{
    int cycle_count = CYCLE_START;
    WINDOW *win;
    char ***title = init_screen(&win);

    l_reverse_champion(&vm->champions);
    while (exec_vm_cycle(vm, cycle_count, win, title) != 0 &&
    (cycle_count < vm->dump_freq || vm->dump_freq == -1))
        ++cycle_count;
    endwin();
    delwin(win);
    a_double_free(title);
    if (vm->last_live != NULL)
        my_printf("The player %d(%s) has won.\n", vm->last_live->id,
        vm->last_live->data.prog_name);
    else
        my_putstr("The player 0() has won.\n", 1);
    l_free_champion(&vm->champions);
    return 0;
}
