##
## EPITECH PROJECT, 2023
## new_folder
## File description:
## Makefile
##

SRC	=	main.c	\
		linked_list.c	\
		file_checker.c	\
		informations_arrays.c	\
		ncurses.c	\
		is_larger.c	\
		mooving.c	\

OBJ	=	$(SRC:.c=.o)

NAME =	my_sokoban

CFLAGS =	-g

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy -lncurses
	make fclean -C lib/my
	make clean

clean:
	rm -f $(OBJ)
	rm -f lib/my/libmy.a
	rm -f coding-style-reports.log

fclean: clean
		rm -f $(NAME)

re: fclean all
