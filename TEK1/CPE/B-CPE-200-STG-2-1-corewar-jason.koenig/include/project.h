/*
** EPITECH PROJECT, 2023
** PROJET.H
** File description:
** List of functions avaliable in the project.
*/

#ifndef PROJECT
    #define PROJECT
    #define CYCLE_START 0
    #define PAID_START -1

    #include "my.h"
    #include "op.h"
    #include <stdbool.h>

typedef enum data_type {
    REGISTER,
    DIRECT,
    INDIRECT
} data_type_t;

typedef struct champions {
    header_t data;
    char r1[REG_SIZE * 2 + 1];
    char r2[REG_SIZE * 2 + 1];
    char r3[REG_SIZE * 2 + 1];
    char r4[REG_SIZE * 2 + 1];
    char r5[REG_SIZE * 2 + 1];
    char r6[REG_SIZE * 2 + 1];
    char r7[REG_SIZE * 2 + 1];
    char r8[REG_SIZE * 2 + 1];
    char r9[REG_SIZE * 2 + 1];
    char r10[REG_SIZE * 2 + 1];
    char r11[REG_SIZE * 2 + 1];
    char r12[REG_SIZE * 2 + 1];
    char r13[REG_SIZE * 2 + 1];
    char r14[REG_SIZE * 2 + 1];
    char r15[REG_SIZE * 2 + 1];
    char r16[REG_SIZE * 2 + 1];
    int carry;
    int pc;
    int id;
    int map_id;
    int cycle_life;
    int paid;
    bool is_alive;
    bool is_clone;
    struct champions *next;
} champions_t;

typedef struct corewar {
    char memory[MEM_SIZE * 2 + 1];
    char mem_owner[MEM_SIZE + 1];
    champions_t *champions;
    champions_t *last_live;
    int dump_freq;
    int count;
    int nb_live;
    int cycle_die;
    int vitals;
} corewar_t;

typedef struct corebag {
    corewar_t *vm;
    champions_t *champion;
    int arg1_type;
    int arg2_type;
    int arg3_type;
    int arg1;
    int arg2;
    int arg3;
    int cmd_id;
    int head_pos;
} corebag_t;

typedef struct champion_shema {
    int arg_a;
    int arg_n;
    char *path;
    struct champion_shema *next;
} champion_shema_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    void (*func_ref)(corebag_t *);
} op_t;

// OP_TAB
extern op_t op_tab[];

// fork lib functions
void l_add_shema(champion_shema_t **list, int arg_a, int arg_n, char *path);
void l_free_shema(champion_shema_t **list);
int l_size_shema(champion_shema_t **list);
void l_reverse_shema(champion_shema_t **list);
void l_add_champion(champions_t **list);
void l_free_champion(champions_t **list);
void l_reverse_champion(champions_t **list);
int l_size_champion(champions_t **list);
void s_copy_from(char *dest, char const *src, int j);
long long n_revbase(char *nb, int base, int max);
char *n_base_zero(unsigned long long nb, int base);
void s_copy_from_to(char *dest, char const *src, int j, int k);
void a_double_free(char ***array);

// program functions
int help_function(void);
void exec_function_selector(corewar_t *vm, champions_t *champion,
    char *action);
corebag_t *create_bag(corebag_t *bag, corewar_t *vm,
    champions_t *champion, int cmd);

//Instructions function
int get_register(int number, champions_t *champion);
void put_register(int number, int value, champions_t *champion);
void cor_add(corebag_t *bag);
void cor_aff(corebag_t *corebag);
void cor_and(corebag_t *corebag);
void cor_ld(corebag_t *my_bagpack);
void cor_ldi(corebag_t *corebag);
void cor_fork(corebag_t *corebag);
void cor_lfork(corebag_t *corebag);
void cor_live(corebag_t *bag);
void cor_lld(corebag_t *my_bagpack);
void cor_lldi(corebag_t *corebag);
void cor_or(corebag_t *corebag);
void cor_xor(corebag_t *corebag);
void cor_st(corebag_t *corebag);
void cor_sti(corebag_t *bag);
void cor_sub(corebag_t *bag);
void cor_zjump(corebag_t *corebag);

// secure lib functions
int secure_getnbr(int *stock, char *val);

// init functions
void init_vm(corewar_t *vm);
void init_champion(champions_t *champion);
void init_register(char reg[REG_SIZE * 2 + 1]);

// load functions
int load_argument(champion_shema_t **id, int ac, char **av, int *i);
int load_shema(corewar_t *vm, champion_shema_t *shema);
int load_champion(corewar_t *vm, champion_shema_t *shema, int nb, int i);

// store functions
void store_data(int fd, corewar_t *vm, champion_shema_t *shema);

// exec functions
int exec_vm(corewar_t *vm);
void fork_champion(champions_t *src, champions_t *dest, corewar_t *vm, int pc);

// write functions
int msg(int exit_code, int port, int nb, ...);
void dump_memory(corewar_t *vm);
void write_arena(int pc, int value, corebag_t *bag, int size);

// translate functions
unsigned int rev_endian(unsigned int val);
int lrev_endian(int val);
char *get_hexa_base(int nb, int size);
void get_indirect(int size, corebag_t *bag);

// verify functions
int verify_magic(int fd);
int verify_header(int fd, champions_t *champion);
int get_carry(int register_nb, champions_t *champion);

#endif
