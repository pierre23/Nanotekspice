##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

CXX =	g++

NAME =	nanotekspice

CPPFLAGS += -I../../include/

RM =	rm -f

SRC =	main.cpp	\
	Parser.cpp

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
