##
## EPITECH PROJECT, 2023
## MAKEFILE MAIN
## File description:
## A program that do simple operation.
##

SRC	=	src/main.c	\
		src/robots.c	\
		src/counter.c	\
		src/sort.c	\
		src/data/load.c	\
		src/data/store.c	\
		src/data/parsing.c	\
		src/data/store/store_link.c	\
		src/data/store/store_nb_robot.c	\
		src/data/store/store_room.c	\
		src/build/init_labyrinth.c	\
		src/build/robot/add_robot_to_list.c	\
		src/build/robot/create_robot_list.c	\
		src/build/robot/free_robot_list.c	\
		src/build/links/add_room_link.c	\
		src/build/links/free_room_links.c	\
		src/build/links/reverse_room_links.c	\
		src/build/links/sort_room_list.c	\
		src/build/room/add_room_to_list.c	\
		src/build/room/free_room_list.c	\
		src/build/room/reverse_room_list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	amazed

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc $(SRC) -o $(NAME) -L. -lmy -g

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:	fclean all
