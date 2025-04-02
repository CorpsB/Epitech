##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## A Makefile that compiles the libmy.
##

INCLUDES	=	../../include/my.h	\
				../../include/hashtable.h	\

ARRAY	=	./array/

GRAPHICS	=	./graphics/

LIST	=	./linked_list/

MATH	=	./math/

STRING	=	./string/

MAIN	=	../../

SRC	=	$(ARRAY)my_show_int_array.c	\
		$(ARRAY)my_show_str_array.c	\
		$(ARRAY)my_sort_int_array.c	\
		$(ARRAY)my_str_to_word_array.c	\
		$(GRAPHICS)get_color.c	\
		$(LIST)kj_free_list.c	\
		$(LIST)kj_put_in_chain.c	\
		$(LIST)my_concat_list.c	\
		$(LIST)my_params_to_list.c	\
		$(LIST)my_rev_list.c	\
		$(LIST)my_list_size.c	\
		$(LIST)kj_list_sort.c	\
		$(LIST)my_display_list.c	\
		$(LIST)my_delete_in_list.c	\
		$(MATH)kj_convert_base.c	\
		$(MATH)kj_count_number.c	\
		$(MATH)kj_getfloat.c	\
		$(MATH)kj_reverse_base.c	\
		$(MATH)kj_xposant.c	\
		$(MATH)my_compute_square_root.c	\
		$(MATH)my_getnbr.c	\
		$(MATH)my_is_prime.c	\
		$(MATH)my_putnbr.c	\
		$(STRING)kj_atomize_char.c	\
		$(STRING)kj_find_in_str.c	\
		$(STRING)kj_int_to_str.c	\
		$(STRING)my_putchar.c	\
		$(STRING)my_putstr.c	\
		$(STRING)my_revstr.c	\
		$(STRING)my_strcat.c	\
		$(STRING)my_strcmp.c	\
		$(STRING)my_strcpy.c	\
		$(STRING)my_strdup.c	\
		$(STRING)my_str_isalpha.c	\
		$(STRING)my_str_isnum.c	\
		$(STRING)my_str_isprintable.c	\
		$(STRING)my_str_islower.c	\
		$(STRING)my_str_isupper.c	\
		$(STRING)my_strlen.c	\
		$(STRING)my_strlowcase.c	\
		$(STRING)my_strncmp.c	\
		$(STRING)my_strncpy.c	\
		$(STRING)my_strstr.c	\
		$(STRING)my_strupcase.c	\
		$(STRING)my_substr.c	\
		$(STRING)kj_stracmp.c	\
		$(MAIN)del.c	\
		$(MAIN)hashtable.c	\
		$(MAIN)insert.c	\
		$(MAIN)hash.c	\
		$(MAIN)search.c	\

OBJ	=	my_show_int_array.o	\
		my_show_str_array.o	\
		my_sort_int_array.o	\
		my_str_to_word_array.o	\
		get_color.o	\
		kj_free_list.o	\
		kj_put_in_chain.o	\
		my_concat_list.o	\
		my_params_to_list.o	\
		my_rev_list.o	\
		kj_convert_base.o	\
		kj_count_number.o	\
		kj_getfloat.o	\
		kj_reverse_base.o	\
		kj_xposant.o	\
		my_compute_square_root.o	\
		my_getnbr.o	\
		my_is_prime.o	\
		my_putnbr.o	\
		kj_atomize_char.o	\
		kj_find_in_str.o	\
		kj_int_to_str.o	\
		my_putchar.o	\
		my_putstr.o	\
		my_revstr.o	\
		my_strcat.o	\
		my_strcmp.o	\
		my_strcpy.o	\
		my_strdup.o	\
		my_str_isalpha.o	\
		my_str_isnum.o	\
		my_str_isprintable.o	\
		my_str_islower.o	\
		my_str_isupper.o	\
		my_strlen.o	\
		my_strlowcase.o	\
		my_strncmp.o	\
		my_strncpy.o	\
		my_strstr.o	\
		my_strupcase.o	\
		my_substr.o	\
		kj_list_sort.o	\
		kj_stracmp.o	\
		my_list_size.o	\
		my_display_list.o	\
		my_delete_in_list.o	\
		del.o	\
		hashtable.o	\
		insert.o	\
		hash.o	\
		search.o	\

NAME	=	libhashtable.a

all:
	gcc -c $(SRC) -include $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	find -name "*.o" -delete -o -name "*.gch" -delete
	cp $(NAME) ../..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
