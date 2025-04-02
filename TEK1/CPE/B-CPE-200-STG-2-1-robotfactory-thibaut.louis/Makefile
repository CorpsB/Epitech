##
## EPITECH PROJECT, 2023
## B-MUL-100-STG-1-1-my_radar-thibaut.louis
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/print_help.c	\
		src/header.c	\
		src/opcode.c	\

OBJ	=	$(SRC:.c=.o)

NAME =	asm

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib
	gcc -o $(NAME) $(OBJ) -L lib -lmy

clean:
	rm -f $(OBJ)
	rm -f lib/libmy.a
	rm -f libmy.a
	rm -f mixword

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
