##
## EPITECH PROJECT, 2023
## MAKEFILE MAIN
## File description:
## A program that do simple operation.
##

SRC	=	src/main.c	\
		src/init.c	\
		src/exec/history.c	\
		src/exec/builtin/disp_history.c	\
		src/exec/builtin/excl_history.c	\
		src/parse/env/get_access.c	\
		src/parse/env/get_path.c	\
		src/parse/env/get_user.c	\
		src/parse/globbings.c	\
		src/parse/parser.c	\
		src/parse/builder.c	\
		src/parse/error.c	\
		src/parse/config/open_rc.c	\
		src/parse/config/save_history.c	\
		src/parse/config/spe_variables.c	\
		src/parse/carac/pipe.c	\
		src/parse/carac/history.c	\
		src/parse/carac/semicolon.c	\
		src/parse/carac/parentheses.c	\
		src/parse/carac/backticks.c	\
		src/parse/carac/inhibitors.c	\
		src/parse/operators/or.c	\
		src/parse/operators/and.c	\
		src/exec/builtin/env/display_env.c	\
		src/exec/builtin/change_dir.c	\
		src/exec/builtin/env/set_env.c	\
		src/exec/builtin/env/unset_env.c	\
		src/exec/builtin/variables/get_sys_variable.c	\
		src/exec/builtin/variables/reveal_variables.c	\
		src/exec/builtin/variables/set/get_tab_by_arg.c	\
		src/exec/builtin/variables/set/set.c	\
		src/exec/builtin/variables/aliases/alias.c	\
		src/exec/builtin/variables/aliases/unalias.c	\
		src/exec/builtin/variables/aliases/redirect_alias.c	\
		src/exec/pipe.c	\
		src/exec/pipeline.c	\
		src/exec/chevron.c	\
		src/exec/folder_utils.c	\
		src/exec/core/unbuiltin.c	\
		src/exec/core/prompt.c	\
		src/exec/core/cmd.c	\
		src/exec/line_editions/advanced_ctrl.c	\
		src/exec/line_editions/termios.c	\
		src/exec/line_editions/line_edition.c	\
		src/exec/line_editions/arrows.c	\
		src/exec/line_editions/cursor.c	\
		src/exec/line_editions/tabs.c	\
		lib/my/others/a_sort_int.c	\
		lib/my/others/n_convert_s.c	\
		lib/my/others/n_prime.c	\
		lib/my/others/n_isprime.c	\
		lib/my/others/n_power.c	\
		lib/my/others/n_revbase.c	\
		lib/my/others/n_size.c	\
		lib/my/others/my_stracmp.c	\
		lib/my/others/my_strcmp.c	\
		lib/my/others/s_copy.c	\
		lib/my/others/s_lower.c	\
		lib/my/others/s_upper.c	\
		lib/my/others/my_strncmp.c	\
    	lib/my/others/my_strscmp.c	\
		lib/my/others/s_ncopy.c	\
		lib/my/others/my_strstr.c	\
		lib/my/others/s_reverse.c	\
		lib/my/others/s_search.c	\
		lib/my/others/my_strlen.c	\
		lib/my/others/s_count.c	\
		lib/my/others/a_size.c	\
		lib/my/stdlib/l_add.c	\
		lib/my/stdlib/l_convert_a.c	\
		lib/my/stdlib/l_display.c	\
		lib/my/stdlib/l_free.c	\
		lib/my/stdlib/l_merge.c	\
		lib/my/stdlib/l_size.c	\
		lib/my/stdlib/l_remove.c	\
		lib/my/stdlib/l_reverse.c	\
		lib/my/stdlib/l_sort.c	\
		lib/my/stdlib/n_base.c	\
		lib/my/stdlib/s_convert_f.c	\
		lib/my/stdlib/s_convert_n.c	\
		lib/my/stdlib/my_strdup.c	\
		lib/my/stdlib/my_substr.c	\
		lib/my/stdlib/my_strcat.c	\
		lib/my/stdlib/s_remove.c	\
		lib/my/stdlib/a_free.c	\
		lib/my/stdlib/a_convert_s.c	\
		lib/my/stdlib/s_convert_a.c	\
		lib/my/stdlib/a_dup.c	\
		lib/my/stdlib/my_getline.c	\
		lib/my/stdlib/my_strtok.c	\
		lib/my/stdlib/s_insert.c	\
		lib/my/stdlib/l_file.c	\
		lib/my/stdlib/s_clean.c	\
		lib/my/unistd/a_display_n.c	\
		lib/my/unistd/a_display_s.c	\
		lib/my/unistd/my_putchar.c	\
		lib/my/unistd/my_putstr.c	\
		lib/my/unistd/my_putnbr.c	\
		lib/my/stdarg/my_printf.c	\
		lib/my/fcntl/my_readfile.c

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
