NAME = ft
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
INCLUDES = -I ./ -I ./containers -I ./rb_tree -I ./functions
OBJ = $(SRC:%.cpp=%.o)

REMOVE = rm -rf

USE_STD=0
TIME_TRACK=1
GREEN='\033[0;32m'
PURPLE='\033[0;34m'
BLUE='\033[0;36m'
WHITE='\033[0;37m'

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c -D USE_STD=$(USE_STD) -D TIME_TRACK=$(TIME_TRACK) -o $@ $<  $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

clean_compares:
	rm std_output.txt ft_output.txt

fclean: clean
	rm -rf $(NAME)

re: fclean all

evaluation:
	$(MAKE) re USE_STD=1 TIME_TRACK=0 && ./ft > std_output.txt
	$(MAKE) re USE_STD=0 TIME_TRACK=0 && ./ft > ft_output.txt
	diff ft_output.txt std_output.txt
	printf $(GREEN)
	printf "OK - FT IS EQUAL STD"

time_track:
	$(MAKE) re USE_STD=1 TIME_TRACK=1
	printf $(PURPLE)
	printf "\n\nSTD TIME\n\n"
	./ft | grep Elapsed && printf $(WHITE) && printf "\n\n"
	$(MAKE) re USE_STD=0 TIME_TRACK=1
	printf $(BLUE)
	printf "\n\nFT TIME\n\n"
	./ft | grep Elapsed

valgrind: all
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all ./ft

debug: set_debug_flag re
	echo "\033[0;31mdebbuger active"

set_debug_flag:
	$(eval CC = c++ -g -fsanitize=address)

.PHONY: fclean re clean all evaluation set_debug_flag debug valgrind
