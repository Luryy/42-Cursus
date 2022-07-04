# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 07:48:42 by lyuri-go          #+#    #+#              #
#    Updated: 2021/11/01 17:20:01 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	push_swap

CHECKER_NAME	=	checker

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror
LIBRARIES = -L$(LIBFT_PATH) -lft
INCLUDES = -I$(INCLUDES_PATH) -I$(LIBFT_PATH)

MAKE_EXTERNAL = make -C
REMOVE = rm -f
SAFE_MAKEDIR = mkdir -p

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs

LIBFT = libft
LIBFT_PATH = ./$(LIBS_PATH)/$(LIBFT)

SOURCE_FILES =	main.c ft_init_args.c ft_clean.c ft_operations_helpers.c \
				ft_operations_s_p.c ft_operations_r.c ft_operations_rr.c \
				ft_index.c ft_sort.c ft_content_info.c ft_utils.c \
				ft_sequence_tag.c ft_rotator.c ft_content_calc.c

SOURCE_B_FILES = ft_checker_bonus.c ft_init_args.c ft_clean.c \
				ft_operations_s_p.c ft_operations_r.c ft_operations_rr.c \
				ft_index.c ft_sort.c ft_content_info.c ft_utils.c \
				ft_sequence_tag.c ft_rotator.c ft_content_calc.c \
				ft_operations_helpers.c

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

SOURCES_B = $(addprefix $(SOURCES_PATH)/,$(SOURCE_B_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

OBJECTS_B = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_B_FILES)))

HEADERS_FILES = push_swap.h
HEADERS_FDF = $(addprefix $(INCLUDES_PATH)/,$(HEADERS_FILES))

all:	$(LIBFT) $(NAME)

bonus:	$(LIBFT) $(CHECKER_NAME)

debug: set_debug_flag re
	echo "\033[0;31mdebbuger active"

set_debug_flag:
	$(eval CC = gcc -g)

$(NAME):	$(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(INCLUDES) $(LIBRARIES) -o $(NAME)

$(CHECKER_NAME): $(OBJECTS_B)
	$(CC) $(FLAGS) $(OBJECTS_B) $(INCLUDES) $(LIBRARIES) -o $(CHECKER_NAME)

$(LIBFT):
	$(MAKE_EXTERNAL) $(LIBFT_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADERS_FDF)
		$(SAFE_MAKEDIR) $(OBJECTS_PATH)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) clean

libft_fclean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

clean: libft_clean
	$(REMOVE) $(OBJECTS) $(OBJECTS_B)

fclean: clean libft_fclean
	$(REMOVE) $(NAME) $(CHECKER_NAME)

re: fclean all

compress:
	tar -cf ./libs/libs.tar ./libs/*

extract:
	tar -xvf ./libs/libs.tar

.PHONY: all re libft_fclean libft_clean clean fclean bonus compress extract

