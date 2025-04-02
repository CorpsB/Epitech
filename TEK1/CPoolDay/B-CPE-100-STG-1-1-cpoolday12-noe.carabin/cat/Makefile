##
## EPITECH PROJECT, 2023
## cat
## File description:
## cat
##

SRC	=	my_putchar.c \
		my_putstr.c \
		cat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME)  $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

auteur:
	echo$(USER) > auteur
