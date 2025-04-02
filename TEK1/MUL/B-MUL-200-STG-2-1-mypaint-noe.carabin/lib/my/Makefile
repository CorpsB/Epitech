##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

LINK_ASSETS = ../../assets/

ASSETS = $(LINK_ASSETS)paint.c	\
	$(LINK_ASSETS)init.c	\
	$(LINK_ASSETS)event_handler.c	\
	$(LINK_ASSETS)music_manager.c	\
	$(LINK_ASSETS)drop_menus.c	\
	$(LINK_ASSETS)buttons.c	\
	$(LINK_ASSETS)utils.c	\
	$(LINK_ASSETS)analyze_button.c	\
	$(LINK_ASSETS)analyze_menu.c	\
	$(LINK_ASSETS)draw.c	\
	$(LINK_ASSETS)paint_drawing.c	\
	$(LINK_ASSETS)dm_buttons_actions.c	\
	$(LINK_ASSETS)pen_color_actions.c	\
	$(LINK_ASSETS)pen_size_actions.c	\
	$(LINK_ASSETS)tools_actions.c

SRC = 	my_compute_power_rec.c \
	my_compute_square_root.c \
	my_find_prime_sup.c \
	my_getnbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_putchar.c \
	my_putnbr.c \
	my_putstr.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_sort_in_array.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c	\
	my_rev_list.c 	\
	my_strdup.c	\
	my_list_size.c	\
	my_put_in_chain.c	\
	tc_get_scientif.c	\
	tc_my_int_to_str.c	\
	tc_put_scientif.c	\
	tc_rev_bin.c	\
	tc_two_complement.c	\
	kj_getfloat.c	\
	kj_chain_to_str.c	\
	kj_free_list.c	\
	kj_putfloat.c	\
	kj_xposant.c	\
	kj_count_number.c	\
	kj_charcut_str.c	\
	my_str_to_word_array.c	\
	count_words.c	\
	print_exit.c	\
	my_printf.c

OBJ = *.o

NAME = libmy.a

all: $(NAME)

${NAME}:
	gcc -c $(SRC) $(ASSETS)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)
re:
	fclean
	all
