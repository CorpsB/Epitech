/*
** EPITECH PROJECT, 2023
** INIT
** File description:
** Project init file.
*/

#include "../../include/project.h"

void init_vm(corewar_t *vm)
{
    int mem_size = MEM_SIZE * 2;
    int owner_size = MEM_SIZE;

    vm->dump_freq = -1;
    vm->champions = NULL;
    for (int i = 0; i < mem_size; ++i)
        vm->memory[i] = '0';
    vm->memory[mem_size] = '\0';
    for (int i = 0; i < owner_size; ++i)
        vm->mem_owner[i] = '0';
    vm->memory[owner_size] = '\0';
    vm->count = 1;
    vm->cycle_die = CYCLE_TO_DIE;
    vm->nb_live = 0;
    vm->last_live = NULL;
    vm->vitals = 2222;
}

void init_register(char reg[REG_SIZE * 2 + 1])
{
    int reg_size = REG_SIZE * 2;

    for (int i = 0; i < reg_size; ++i)
        reg[i] = '0';
    reg[reg_size] = '\0';
}

static void init_registers(champions_t *champion)
{
    init_register(champion->r1);
    init_register(champion->r2);
    init_register(champion->r3);
    init_register(champion->r4);
    init_register(champion->r5);
    init_register(champion->r6);
    init_register(champion->r7);
    init_register(champion->r8);
    init_register(champion->r9);
    init_register(champion->r10);
    init_register(champion->r11);
    init_register(champion->r12);
    init_register(champion->r13);
    init_register(champion->r14);
    init_register(champion->r15);
    init_register(champion->r16);
}

void init_champion(champions_t *champion)
{
    champion->carry = 1;
    champion->paid = PAID_START;
    champion->cycle_life = 0;
    champion->is_alive = true;
    champion->is_clone = false;
    init_registers(champion);
}

static void fork_registers(champions_t *src, champions_t *dest)
{
    s_copy(dest->r1, src->r1);
    s_copy(dest->r2, src->r2);
    s_copy(dest->r3, src->r3);
    s_copy(dest->r4, src->r4);
    s_copy(dest->r5, src->r5);
    s_copy(dest->r6, src->r6);
    s_copy(dest->r7, src->r7);
    s_copy(dest->r8, src->r8);
    s_copy(dest->r9, src->r9);
    s_copy(dest->r10, src->r10);
    s_copy(dest->r11, src->r11);
    s_copy(dest->r12, src->r12);
    s_copy(dest->r13, src->r13);
    s_copy(dest->r14, src->r14);
    s_copy(dest->r15, src->r15);
    s_copy(dest->r16, src->r16);
}

void fork_champion(champions_t *src, champions_t *dest, corewar_t *vm, int pc)
{
    dest->carry = src->carry;
    dest->cycle_life = src->cycle_life;
    s_copy(dest->data.comment, src->data.comment);
    s_copy(dest->data.prog_name, src->data.prog_name);
    dest->id = src->id;
    dest->map_id = src->map_id;
    dest->pc = pc;
    dest->paid = PAID_START + 1;
    dest->is_alive = true;
    dest->is_clone = true;
    fork_registers(src, dest);
}
