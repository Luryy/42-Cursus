NAME = animal
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AAnimal.cpp main.cpp Cat.cpp Dog.cpp Brain.cpp
INCLUDES = -I ./
OBJ = $(SRC:%.cpp=%.o)

REMOVE = rm -rf

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<  $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean re clean all
