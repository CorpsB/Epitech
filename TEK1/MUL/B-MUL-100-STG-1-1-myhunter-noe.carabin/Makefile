##
## EPITECH PROJECT, 2023
## Printf
## File description:
## Printf like a lib
##

SRC	=	main.c	\
		main2.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system \
	-lcsfml-audio
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re:	fclean all
