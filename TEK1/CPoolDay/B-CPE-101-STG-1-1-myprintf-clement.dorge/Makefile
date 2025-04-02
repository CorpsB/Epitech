##
## EPITECH PROJECT, 2023
## Printf
## File description:
## Printf like a lib
##

SRC	=	mini_c.c	\
		mini_d.c	\
		mini_i.c	\
		mini_o.c	\
		mini_s.c	\
		mini_u.c	\
		mini_e.c	\
		mini_eup.c	\
		mini_f.c	\
		mini_x.c	\
		mini_xup.c	\
		mini_p.c	\
		bonus/mini_b.c	\
		my_putchar.c	\
		my_putnbr.c	\
		my_putstr.c	\
		main_printf.c	\
		my_pointer.c	\
		my_unsigned_int.c	\
		my_put_unsigned_int.c	\
		bonus/my_binary.c	\
		my_put_hexadecimal.c	\
		my_put_hexadecimal_low.c	\
		mini_g.c	\
		mini_upg.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):		$(OBJ)
	ar rc $(NAME)  $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re:	fclean all
