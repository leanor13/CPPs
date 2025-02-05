NAME = zombie_horde

SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Zombie.hpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
