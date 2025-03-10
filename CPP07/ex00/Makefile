NAME = swap_test
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
HEADERS = whatever.hpp

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: clean all

.PHONY: all clean re
