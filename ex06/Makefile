NAME = harlFilter
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Harl.cpp
INCLUDES = -I ./
OBJ = $(SRC:%.cpp=%.o)

REMOVE = rm -rf

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean re clean all
