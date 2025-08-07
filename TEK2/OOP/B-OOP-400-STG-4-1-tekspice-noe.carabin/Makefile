##
## EPITECH PROJECT, 2025
## B-OOP-400-STG-4-1-tekspice-noe.carabin
## File description:
## Makefile
##

FLAGS	= -std=c++20 -Wall -Wextra -Werror -g

SRC	=	main.cpp	\
		Nts.cpp	\
		parser/ComponentFactory.cpp	\
		parser/FileParser.cpp	\
		components/AComponent.cpp	\
		components/0_base/LogicalComponent.cpp	\
		components/0_base/SmartComponent.cpp	\
		components/0_base/LoopComponent.cpp	\
		components/0_base/LoopLKComponent.cpp	\
		components/1_required/FullAdderComponent.cpp	\
		components/1_required/LATCH/SRLatchPRComponent.cpp	\
		components/1_required/LATCH/DLatchPRComponent.cpp	\
		components/1_required/DFlipFlopPRComponent.cpp	\
		components/1_required/DFlipFlopPRLKComponent.cpp	\
		components/2_special/ClockComponent.cpp	\
		components/2_special/OutputComponent.cpp	\
		components/2_special/TrueComponent.cpp	\
		components/2_special/FalseComponent.cpp	\
		components/3_elementary/AND/AndComponent.cpp	\
		components/3_elementary/OR/OrComponent.cpp	\
		components/3_elementary/XOR/XorComponent.cpp	\
		components/3_elementary/NOT/NotComponent.cpp	\
		components/3_elementary/NOR/NorComponent.cpp	\
		components/3_elementary/NAND/NandComponent.cpp	\
		components/3_elementary/NAND/Nand3Component.cpp	\
		components/4_gates/_4001Component.cpp	\
		components/4_gates/_4011Component.cpp	\
		components/4_gates/_4030Component.cpp	\
		components/4_gates/_4069Component.cpp	\
		components/4_gates/_4071Component.cpp	\
		components/4_gates/_4081Component.cpp	\
		components/5_advanced/_4008Component.cpp	\
		components/5_advanced/_4013Component.cpp	\
		components/5_advanced/_4017Component.cpp	\
		components/5_advanced/LoggerComponent.cpp	\

OBJ	=	$(SRC:.cpp=.o)
NAME	=	nanotekspice

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
