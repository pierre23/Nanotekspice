##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CXX =	g++ -g3 -Wfatal-errors

NAME =	nanotekspice

CPPFLAGS += -I./include/ -W -Werror -Wextra -pedantic -Wall

RM =	rm -f

SRC =	src/main.cpp			\
	src/chipset/AChipset.cpp	\
	src/gate/gate.cpp		\
	src/parser/Parser.cpp		\
	src/chipset/C4001.cpp		\
	src/chipset/C4013.cpp		\
	src/chipset/C4008.cpp		\
	src/chipset/C4011.cpp		\
	src/chipset/C4030.cpp		\
	src/chipset/C4069.cpp		\
	src/chipset/C4071.cpp		\
	src/chipset/C4081.cpp		\
	src/chipset/Clock.cpp		\
	src/chipset/True.cpp		\
	src/chipset/False.cpp		\
	src/logical_gate/AndGate.cpp	\
	src/logical_gate/FlipFlopGate.cpp	\
	src/logical_gate/NandGate.cpp	\
	src/logical_gate/NorGate.cpp	\
	src/logical_gate/ClockGate.cpp	\
	src/logical_gate/NxorGate.cpp	\
	src/logical_gate/NotGate.cpp	\
	src/logical_gate/OrGate.cpp	\
	src/logical_gate/AddGate.cpp	\
	src/logical_gate/XorGate.cpp	\
	src/logical_gate/TrueGate.cpp	\
	src/logical_gate/FalseGate.cpp	\
	src/chipset/input.cpp		\
	src/chipset/output.cpp		\
	src/Shell.cpp			\
	src/Error.cpp

OBJS =	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
