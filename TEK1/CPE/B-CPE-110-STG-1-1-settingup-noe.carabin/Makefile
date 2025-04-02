##
## EPITECH PROJECT, 2023
## do op
## File description:
## makefile
##

SRC	=	error_detector.c	\
		find_square.c	\
		map_generator.c	\
		my_putstr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up

CFLAGS  =	-g

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
