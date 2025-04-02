##
## EPITECH PROJECT, 2023
## B-MUL-100-STG-1-1-my_radar-thibaut.louis
## File description:
## Makefile
##

SRC	=	my/Pas_malloc/my_putchar.c	\
		my/Pas_malloc/my_strcpy.c  \
		my/Pas_malloc/my_strlen.c 	\
		my/Pas_malloc/my_put_nbr.c	\
		my/Pas_malloc/my_putstr.c	\
		my/Pas_malloc/my_strcmp.c	\
		my/Malloc/my_strdup.c	\
		my/Pas_malloc/my_compute_power_it.c	\
		my/Pas_malloc/my_str_to_int.c	\
		my/Pas_malloc/my_min.c		\
		flags/flag_c.c		\
		flags/flag_d_i.c	\
		flags/flag_e.c		\
		flags/flag_f.c		\
		flags/flag_g.c		\
		flags/flag_p.c		\
		flags/flag_g_maj.c	\
		flags/flag_n.c		\
		flags/flag_o.c		\
		flags/flag_pours.c	\
		flags/flag_s.c		\
		flags/flag_u.c		\
		flags/flag_x.c		\
		flags/flag_xmaj.c	\
		my/my_printf.c	\
		my/Pas_malloc/my_isdigit.c	\
		my/Pas_malloc/my_getnbr.c	\
		my/Pas_malloc/my_revstr.c	\
		my/Malloc/my_str_to_word_array.c	\
		my/Malloc/my_str_cat.c	\
		my/Malloc/tabl_size.c	\
		my/Malloc/tabl_copy.c	\
		my/Malloc/aff_tabl.c	\
		my/Malloc/free_tabl.c	\
		my/Pas_malloc/my_strlowcas.c	\
		my/Pas_malloc/my_strupcas.c	\
		my/Pas_malloc/size_int.c		\
		my/Pas_malloc/my_str_isnum.c	\
		my/Malloc/my_substr.c			\
		my/Malloc/clean_str.c			\
		my/Malloc/my_str_to_word_array_upgrade.c	\
		my/Malloc/clean_array.c	\
		my/Pas_malloc/my_memset.c	\
		my/Pas_malloc/my_atoi.c

OBJ	=	$(SRC:.c=.o)

NAMELI	=	libmy.a

all: $(NAMELI)

$(NAMELI):	$(OBJ)
	gcc -c $(SRC) -g
	ar rc $(NAMELI) $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f $(OBJ)
	rm -f libmy.a

fclean: clean
		rm -f $(NAMELI)

re: fclean all

.PHONY: all clean fclean re
