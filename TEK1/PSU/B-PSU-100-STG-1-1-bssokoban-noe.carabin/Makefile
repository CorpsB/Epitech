##
## EPITECH PROJECT, 2023
## Printf
## File description:
## Printf like a lib
##

SRC	=	bs.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_popup

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc bs.c -lncurses -o my_popup
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re:	fclean all
