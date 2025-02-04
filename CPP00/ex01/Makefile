NAME = phonebook

SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++
RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)  # Link object files instead of re-compiling everything

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@  # Compile .cpp files individually

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
