##
## EPITECH PROJECT, 2023
## do op
## File description:
## makefile
##

SRC	=	lib.c	\
		mainf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

CFLAGS  =	-g

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
