##
## EPITECH PROJECT, 2025
## B-FUN-400-STG-4-1-wolfram-noe.carabin
## File description:
## Makefile
##

EXEC = imageCompressor

BUILD_DIR = $(shell stack path --local-install-root)/bin

all:
	stack build
	mv $(BUILD_DIR)/ImageCompressor-exe ./$(EXEC)

clean:
	stack clean

fclean: clean
	rm -rf .stack-work
	rm -f $(EXEC)

re: clean all
