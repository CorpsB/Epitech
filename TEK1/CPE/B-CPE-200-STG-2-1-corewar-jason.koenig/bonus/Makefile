##
## EPITECH PROJECT, 2023
## MAKEFILE MAIN
## File description:
## A program that do simple operation.
##

SRC	=	../src/main.c	\
		../src/dump.c	\
		../src/verify.c	\
		../src/op.c	\
		../src/translate/endian.c	\
		../src/translate/base.c	\
		../src/translate/indirect.c	\
		../src/core/init.c	\
		../src/core/load.c	\
		exec.c	\
		../src/core/bag.c	\
		../src/core/register.c	\
		../src/core/write.c	\
		../src/extra/secure_lib.c	\
		../src/commands/add.c	\
		../src/commands/aff.c	\
		../src/commands/and.c	\
		../src/commands/fork.c	\
		../src/commands/ld.c	\
		../src/commands/ldi.c	\
		../src/commands/lfork.c	\
		../src/commands/live.c	\
		../src/commands/lld.c	\
		../src/commands/lldi.c	\
		../src/commands/or.c	\
		../src/commands/st.c	\
		../src/commands/sti.c	\
		../src/commands/sub.c	\
		../src/commands/xor.c	\
		../src/commands/zjmp.c	\
		graphical/title/lettera.c	\
		graphical/title/letterc.c	\
		graphical/title/lettere.c	\
		graphical/title/lettero.c	\
		graphical/title/letterr.c	\
		graphical/title/letterw.c	\
		graphical/title/title.c	\
		graphical/arena.c	\
		graphical/champions.c	\
		graphical/cycle.c	\
		graphical/ncurses.c	\
		../lib/my/others/a_sort_int.c	\
		../lib/my/others/n_convert_s.c	\
		../lib/my/others/n_prime.c	\
		../lib/my/others/n_isprime.c	\
		../lib/my/others/n_power.c	\
		../lib/my/others/n_revbase.c	\
		../lib/my/others/n_size.c	\
		../lib/my/others/my_stracmp.c	\
		../lib/my/others/my_strcmp.c	\
		../lib/my/others/s_copy.c	\
		../lib/my/others/s_lower.c	\
		../lib/my/others/s_upper.c	\
		../lib/my/others/my_strncmp.c	\
    	../lib/my/others/my_strscmp.c	\
		../lib/my/others/s_ncopy.c	\
		../lib/my/others/my_strstr.c	\
		../lib/my/others/s_reverse.c	\
		../lib/my/others/s_search.c	\
		../lib/my/others/my_strlen.c	\
		../lib/my/others/s_count.c	\
		../lib/my/others/a_size.c	\
		../lib/my/stdlib/l_add.c	\
		../lib/my/stdlib/l_convert_a.c	\
		../lib/my/stdlib/l_display.c	\
		../lib/my/stdlib/l_free.c	\
		../lib/my/stdlib/l_merge.c	\
		../lib/my/stdlib/l_size.c	\
		../lib/my/stdlib/l_remove.c	\
		../lib/my/stdlib/l_reverse.c	\
		../lib/my/stdlib/l_sort.c	\
		../lib/my/stdlib/n_base.c	\
		../lib/my/stdlib/s_convert_f.c	\
		../lib/my/stdlib/s_convert_n.c	\
		../lib/my/stdlib/my_strdup.c	\
		../lib/my/stdlib/my_substr.c	\
		../lib/my/stdlib/my_strcat.c	\
		../lib/my/stdlib/s_remove.c	\
		../lib/my/stdlib/a_free.c	\
		../lib/my/stdlib/a_convert_s.c	\
		../lib/my/stdlib/a_dup.c	\
		../lib/my/stdlib/my_getline.c	\
		../lib/my/stdlib/my_strtok.c	\
		../lib/my/unistd/a_display_n.c	\
		../lib/my/unistd/a_display_s.c	\
		../lib/my/unistd/my_putchar.c	\
		../lib/my/unistd/my_putstr.c	\
		../lib/my/unistd/my_putnbr.c	\
		../lib/my/stdarg/my_printf.c	\
		../lib/my/fcntl/my_readfile.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) -lcurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
