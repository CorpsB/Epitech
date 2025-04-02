##
## EPITECH PROJECT, 2023
## new_folder
## File description:
## Makefile
##

SRC	=	main.c	\
		two_word_array.c	\
		env.c	\
		cd.c	\
		setenv.c	\
		re_build_env.c	\
		linked_list.c	\
		my_strdup.c	\
		unsetenv.c	\
		free.c	\
		format_str.c	\
		my_error.c	\
		my_substr.c	\
		is_exec.c	\
		semilicon.c	\
		pipe.c	\
		get_nbr.c	\
		bad_archi.c	\
		redirection_error.c	\
		redirection.c	\
		red_searcher.c	\

OBJ	=	$(SRC:.c=.o)

NAME =	mysh

CFLAGS =	-g

all: $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy
	make fclean -C lib/my
	make clean

clean:
	rm -f $(OBJ)
	rm -f lib/my/libmy.a
	rm -f coding-style-reports.log

fclean: clean
		rm -f $(NAME)

re: fclean all
