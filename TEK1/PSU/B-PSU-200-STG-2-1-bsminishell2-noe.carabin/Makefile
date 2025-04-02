##
## EPITECH PROJECT, 2023
## new_folder
## File description:
## Makefile
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME =	my_pipe

CFLAGS =	-g

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy
	make fclean -C lib
	make clean

clean:
	rm -f $(OBJ)
	rm -f lib/my/libmy.a
	rm -f coding-style-reports.log

fclean: clean
		rm -f $(NAME)

re: fclean all
