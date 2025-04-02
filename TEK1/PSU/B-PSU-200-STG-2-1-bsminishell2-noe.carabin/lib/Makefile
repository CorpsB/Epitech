##
## EPITECH PROJECT, 2023
## my_makefile
## File description:
## gcc my librairie
##

SRC	=	my/my_putchar.c	\
		my/my_isneg.c	\
		my/my_put_nbr.c	\
		my/my_putstr.c	\
		my/my_strlen.c	\
		my/my_getnbr.c	\
		my/my_compute_power_rec.c	\
		my/my_compute_square_root.c	\
		my/my_is_prime.c	\
		my/my_find_prime_sup.c	\
		my/my_strcpy.c	\
		my/my_revstr.c	\
		my/my_strcmp.c	\
		my/my_str_isalpha.c	\
		my/my_strdup.c	\
		my/is_alpha_num.c	\
		my/str_str.c	\
		my/table_len.c	\
		my/format_str.c	\
		my/str_len_to.c	\
		my/show_table.c	\
		my/str_to_array.c	\
		linked_list/array_to_list.c	\
		linked_list/del_in_list.c	\
		linked_list/list_to_array.c	\
		linked_list/my_list_size.c	\
		linked_list/my_put_in_list.c	\
		linked_list/my_show_list.c	\
		linked_list/my_show_revlist.c	\
		linked_list/search_from_list.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS =	-g

all:	$(NAME)

$(NAME):		$(OBJ)
	ar rc $(NAME)  $(OBJ)
	mv $(NAME) my
	make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
