##
## EPITECH PROJECT, 2025
## B-ASM-400-STG-4-1-asmminilibc-noe.carabin
## File description:
## Makefile
##

SRC	=	strlen.asm	\
		strchr.asm	\
		strrchr.asm	\
		memset.asm	\
		memcpy.asm	\
		strcmp.asm	\
		memmove.asm	\
		strncmp.asm	\
		strcasecmp.asm	\
		strstr.asm	\
		strpbrk.asm	\
		strcspn.asm	\


OBJ	=	$(SRC:.asm=.o)

NAME	=	libasm.so

all:	$(NAME)

%.o: %.asm
	nasm -f elf64 $< -o $@

$(NAME):	$(OBJ)
	ld -shared -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re