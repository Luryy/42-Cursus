NAME	=	cub3d

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror -O3
LIBRARIES = -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
INCLUDES = -I$(INCLUDES_PATH) -I$(LIBFT_PATH) -I$(MLX_INCLUDE_PATH)

MAKE_EXTERNAL = make -C
REMOVE = rm -rf
SAFE_MAKEDIR = mkdir -p

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs

LIBFT = libft
LIBFT_PATH = ./$(LIBS_PATH)/$(LIBFT)

MLX = minilibx
MLX_PATH = ./$(LIBS_PATH)/$(MLX)
MLX_INCLUDE_PATH = ./$(LIBS_PATH)/$(MLX)/mlx

SOURCE_FILES =	main.c check_map.c

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

SOURCE_DIRS = controllers

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

OBJECTS_DIRS = $(addprefix $(OBJECTS_PATH)/,$(SOURCE_DIRS))

HEADERS_FILES = cub3d.h
HEADERS = $(addprefix $(INCLUDES_PATH)/,$(HEADERS_FILES))

all:	$(LIBFT) $(MLX) $(NAME)

valgrind: all
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./cub3d


debug: set_debug_flag re
	echo "\033[0;31mdebbuger active"

set_debug_flag:
	$(eval CC = gcc -g -fsanitize=address)

$(NAME):	$(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME) $(LIBRARIES)

$(LIBFT):
	$(MAKE_EXTERNAL) $(LIBFT_PATH)

$(MLX):
	$(MAKE_EXTERNAL) $(MLX_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADERS)
		$(SAFE_MAKEDIR) $(OBJECTS_PATH) $(OBJECTS_DIRS)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) clean

libft_fclean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

mlx_clean:
	$(MAKE_EXTERNAL) $(MLX_PATH) clean

clean: libft_clean
	$(REMOVE) $(OBJECTS) $(OBJECTS_B)
	$(REMOVE) $(OBJECTS_PATH)

fclean: clean libft_fclean mlx_clean
	$(REMOVE) $(NAME) $(CHECKER_NAME)

test: re
	./tester.sh

re: fclean all

compress:
	tar -cf ./libs/libs.tar ./libs/*

extract:
	tar -xvf ./libs/libs.tar

.PHONY: all re libft_fclean libft_clean clean fclean compress extract

