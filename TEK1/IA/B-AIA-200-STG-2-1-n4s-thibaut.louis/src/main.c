/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** Project main file.
*/

#include "../include/project.h"

void run_car(void)
{
    direction_t dir;

    dir.dir = 0;
    dir.vit = 0.2;
    send_move("CAR_FORWARD", "0.2");
    sleep(0.05);
    get_infos(&dir);
    dir.pist_length = (dir.left + dir.right) / 2;
    dir.pist_length *= 0.8;
    dir.all_dir = 0;
    while (true) {
        get_infos(&dir);
        get_new_dir(&dir);
        if (dir.all_dir){
            send_move("CAR_FORWARD", "0");
            break;
        }
    }
}

int main(void)
{
    send_move("START_SIMULATION", "");
    run_car();
    sleep(1);
    send_move("STOP_SIMULATION", "");
    sleep(1);
    return 0;
}
