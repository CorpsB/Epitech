##
## EPITECH PROJECT, 2023
## B-MUL-100-STG-1-1-my_radar-thibaut.louis
## File description:
## Makefile
##

SRC	=	my/my_putchar.c	\
		my/my_strcpy.c  \
		my/my_strlen.c 	\
		my/my_put_nbr.c	\
		my/my_putstr.c	\
		my/my_strcmp.c	\
		my/my_strdup.c	\
		my/my_strcat.c	\
		my/my_compute_power_it.c	\
		my/my_str_to_int.c	\
		my/my_min.c		\
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
		my/my_isdigit.c	\
		my/my_atoi.c	\


OBJ	=	$(SRC:.c=.o)

NAMELI	=	libmy.a

all: $(NAMELI)

$(NAMELI):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAMELI) $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f $(OBJ)
	rm -f libmy.a

fclean: clean
		rm -f $(NAMELI)

re: fclean all
