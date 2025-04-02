##
## EPITECH PROJECT, 2023
## organized
## File description:
## organized like a lib
##

SRC	=	main.c	\
		my_strdup.c	\
		sort.c	\
		rev_sort.c	\
		tools.c	\
		disp.c	\
		del.c	\
		add.c	\
		tools2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	organized

CFLAGS = -g

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -o $(NAME) $(OBJ) -L. libshell/libshell.a
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re:	fclean all
