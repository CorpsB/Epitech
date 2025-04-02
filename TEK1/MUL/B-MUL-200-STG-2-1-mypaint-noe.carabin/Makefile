##
## EPITECH PROJECT, 2023
## My Library (Epitech)
## File description:
## Makefile
##

NAME = my_paint

all:
	make -C ./lib/my
	gcc -o $(NAME) main.c -Llib/my -lmy -lcsfml-graphics	\
	-lcsfml-system -lcsfml-window -lcsfml-audio

clean:
	make clean -C ./lib/my

fclean:	clean
	make fclean -C ./lib/my

re:	fclean all
