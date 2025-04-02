##
## EPITECH PROJECT, 2023
## B-MUL-100-STG-1-1-my_radar-thibaut.louis
## File description:
## Makefile
##

SRC	=	my_navy.c	\
		help.c	\
		grille.c	\
		display.c	\
		player1.c	\
		player2.c	\
		tools.c	\
		is_win.c	\
		send_pos.c	\
		attack_result.c	\
		file_extractor.c	\
		send.c	\


OBJ	=	$(SRC:.c=.o)

NAME =	my_navy

CFLAGS =	-g

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib
	gcc -o $(NAME) $(OBJ) -L lib -lmy

clean:
	rm -f $(OBJ)
	rm -f lib/libmy.a

fclean: clean
		rm -f $(NAME)

re: fclean all
