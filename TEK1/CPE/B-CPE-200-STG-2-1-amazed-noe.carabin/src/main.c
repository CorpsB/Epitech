/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../include/amazed.h"

static int amazed_return(int val)
{
    if (val == 127)
        return 84;
    return val;
}

int main(void)
{
    int err_code;
    labyrinth_t laby;

    init_labyrinth(&laby);
    err_code = load_data(&laby);
    if (err_code != 127){
        laby.robots = create_robot_list(&laby);
        counter(&laby);
        if (laby.start->dist == -1)
            err_code = 127;
    }
    if (err_code != 127){
        my_putstr("#moves\n", 1);
        sort_links(&laby);
        while (move_robots(&laby));
    }
    free_robot_list(&laby.robots);
    free_room_list(&laby.rooms);
    return amazed_return(err_code);
}
