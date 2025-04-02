##
## EPITECH PROJECT, 2023
## B-MUL-100-STG-1-1-myradar-noe.carabin
## File description:
## Makefile
##

SRC	=	main.c	\
		file_searcher.c	\
		core.c	\
		plane_colision.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

CFLAGS = -g

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system \
	-lcsfml-audio -lm
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	clear

re:	fclean all
