##
## EPITECH PROJECT, 2023
## do op
## File description:
## makefile
##

SRC	=	getnumber.c	\
		main_do_op.c	\
		op.c

OBJ	=	$(SRC:.c=.o)

NAME	=	do-op

all:	$(NAME)

$(NAME): $(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) -L../lib -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
