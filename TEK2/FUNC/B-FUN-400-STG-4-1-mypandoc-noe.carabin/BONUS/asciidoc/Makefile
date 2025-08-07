##
## EPITECH PROJECT, 2024
## B-FUN-400-STG-4-1-mypandoc-noe.carabin
## File description:
## Makefile
##

NAME=mypandoc

STACK=stack
SP := $(shell $(STACK) path --local-install-root)

$(NAME):
	$(STACK) build
	cp "$(SP)/bin/mypandoc-exe" ./"$(NAME)"
	chmod +x $(NAME)

all: $(NAME)

clean:
	$(STACK) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
