/*
** EPITECH PROJECT, 2023
** AMAZED.H
** File description:
** List of functions avaliable in the projet
*/

#ifndef AMAZED
    #define AMAZED

    #include "my.h"

typedef struct room_link {
    struct room_list *room;
    struct room_link *next;
} room_link_t;

typedef struct room_list {
    char *name;
    int pos_x;
    int pos_y;
    int dist;
    struct robot_list *robot;
    room_link_t *list;
    struct room_list *next;
} room_list_t;

typedef struct robot_list {
    int id;
    room_list_t *room;
    struct robot_list *next;
} robot_list_t;

typedef struct labyrinth {
    int nb_robots;
    int tunnel_count;
    room_list_t *start;
    room_list_t *end;
    room_list_t *rooms;
    robot_list_t *robots;
} labyrinth_t;

// fork lib functions
int s_count_double(char *str, char c, char c2);

// parsing functions
int skip_comment(char *line, int i, int *mode);
int skip_word(char *line, int i);

// read functions
int load_data(labyrinth_t *laby);
char *get_data(void);

// store functions
int store_data(labyrinth_t *laby, char *line);
int store_link(labyrinth_t *laby, char *line, int i);
int store_room(labyrinth_t *laby, char *line, int i, int mode);
int store_nb_robot(labyrinth_t *laby, char *line, int i);

// init functions
void init_labyrinth(labyrinth_t *laby);

// robot list functions
void add_robot_to_list(robot_list_t **list, int id, room_list_t *start);
robot_list_t *create_robot_list(labyrinth_t *laby);
void free_robot_list(robot_list_t **list);

// room list functions
void add_room_to_list(room_list_t **list, char *name, int pos_x, int pos_y);
void free_room_list(room_list_t **list);
void reverse_room_list(room_list_t **list);

// room link list functions
void add_room_link(room_list_t *l1, room_list_t *l2);
void free_room_links(room_link_t **list);
void reverse_room_links(room_link_t **list);
room_link_t *sort_room_list(room_link_t *list);

// algorithm functions
void counter(labyrinth_t *laby);
int move_robots(labyrinth_t *laby);
void sort_links(labyrinth_t *laby);

#endif
