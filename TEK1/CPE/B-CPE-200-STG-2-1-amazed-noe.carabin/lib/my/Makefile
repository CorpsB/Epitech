##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## A Makefile that compiles the libmy.
##

INCLUDES	=	../../include/my.h

SRC	=	others/a_sort_int.c	\
		others/n_convert_s.c	\
		others/n_prime.c	\
		others/n_isprime.c	\
		others/n_power.c	\
		others/n_revbase.c	\
		others/n_size.c	\
		others/my_stracmp.c	\
		others/my_strcmp.c	\
		others/s_copy.c	\
		others/s_lower.c	\
		others/s_upper.c	\
		others/my_strncmp.c	\
        others/my_strscmp.c	\
		others/s_ncopy.c	\
		others/my_strstr.c	\
		others/s_reverse.c	\
		others/s_search.c	\
		others/my_strlen.c	\
		others/s_count.c	\
		others/a_size.c	\
		stdlib/l_add.c	\
		stdlib/l_convert_a.c	\
		stdlib/l_display.c	\
		stdlib/l_free.c	\
		stdlib/l_merge.c	\
		stdlib/l_size.c	\
		stdlib/l_remove.c	\
		stdlib/l_reverse.c	\
		stdlib/l_sort.c	\
		stdlib/n_base.c	\
		stdlib/s_convert_f.c	\
		stdlib/s_convert_n.c	\
		stdlib/my_strdup.c	\
		stdlib/my_substr.c	\
		stdlib/my_strcat.c	\
		stdlib/s_remove.c	\
		stdlib/a_free.c	\
		stdlib/a_convert_s.c	\
		stdlib/a_dup.c	\
		stdlib/my_getline.c	\
		unistd/a_display_n.c	\
		unistd/a_display_s.c	\
		unistd/my_putchar.c	\
		unistd/my_putstr.c	\
		unistd/my_putnbr.c	\
		stdarg/my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) -include $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../../$(NAME)

re:	fclean all
