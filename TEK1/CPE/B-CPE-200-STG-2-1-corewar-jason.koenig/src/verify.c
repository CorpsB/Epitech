/*
** EPITECH PROJECT, 2024
** DUMP MEMORY
** File description:
** Display the content of the memory.
*/

#include "../include/project.h"

int verify_magic(int fd)
{
    int magic;

    read(fd, &magic, 4);
    magic = rev_endian(magic);
    if (magic == COREWAR_EXEC_MAGIC)
        return 0;
    close(fd);
    return 1;
}

int verify_header(int fd, champions_t *champion)
{
    char buff[50];

    read(fd, champion->data.prog_name, PROG_NAME_LENGTH);
    read(fd, buff, 4);
    read(fd, &champion->data.prog_size, 4);
    champion->data.prog_size = rev_endian(champion->data.prog_size);
    read(fd, champion->data.comment, COMMENT_LENGTH);
    read(fd, buff, 4);
    if (champion->data.prog_name[0] == '\0' ||
    champion->data.comment[0] == '\0' || champion->data.prog_size == 0) {
        close(fd);
        return 1;
    }
    return 0;
}

void store_data(int fd, corewar_t *vm, champion_shema_t *shema)
{
    char *buff;
    int nb_tmp = 0;
    int ptn = vm->champions->pc;

    for (int i = 0; i < vm->champions->data.prog_size; ++i){
        vm->mem_owner[ptn / 2] = vm->champions->map_id + 48;
        read(fd, &nb_tmp, 1);
        buff = n_base(nb_tmp, 16);
        if (buff[0] != '\0' && buff[1] == '\0'){
            s_copy_from(vm->memory, "0", ptn);
            s_copy_from(vm->memory, buff, ptn + 1);
        }
        if (buff[0] == '\0')
            s_copy_from(vm->memory, "00", ptn);
        if (buff[0] != '\0' && buff[1] != '\0')
            s_copy_from(vm->memory, buff, ptn);
        free(buff);
        ptn += 2;
    }
}
