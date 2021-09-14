# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 08:39:36 by lyuri-go          #+#    #+#              #
#    Updated: 2021/09/14 18:52:18 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf.a

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror -O3
FLAGS	=	-O3
LIBRARIES = -L$(MLX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -L$(LIBFT_PATH) -lft
INCLUDES = -I$(INCLUDES_PATH) -I$(LIBFT_PATH) -I$(MLX_PATH)

MAKE_EXTERNAL = make -C
REMOVE = rm -f
SAFE_MAKEDIR = mkdir -p

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs

LIBFT = libft
LIBFT_PATH = ./$(LIBS_PATH)/$(LIBFT)

MLX = minilibx
MLX_PATH = ./$(LIBS_PATH)/$(MLX)

SOURCE_FILES = main.c

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

HEADERS_FILES = fdf.h
HEADERS_FDF = $(addprefix $(INCLUDES_PATH)/,$(HEADERS_FILES))

all:	$(NAME)

$(NAME):	libft mlx $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(INCLUDES) $(LIBRARIES) -o $(NAME)

libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH)

mlx:
	$(MAKE_EXTERNAL) $(MLX_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADERS_FDF)
		$(SAFE_MAKEDIR) $(OBJECTS_PATH)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

libft_fclean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

mlx_clean:
	$(MAKE_EXTERNAL) $(MLX_PATH) clean

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean libft_fclean mlx_clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: libft all re libft_fclean clean fclean
