NAME = RPN
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = RPN.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
