# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 22:24:23 by lyuri-go          #+#    #+#              #
#    Updated: 2021/11/24 19:06:06 by elima-me         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

# BONUS_NAME	=	checker

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror
LIBRARIES = -L$(LIBFT_PATH) -lft -lreadline
INCLUDES = -I$(INCLUDES_PATH) -I$(LIBFT_PATH)

MAKE_EXTERNAL = make -C
REMOVE = rm -rf
SAFE_MAKEDIR = mkdir -p

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs

LIBFT = libft
LIBFT_PATH = ./$(LIBS_PATH)/$(LIBFT)

SOURCE_FILES =	main.c \
				controllers/ft_execute.c controllers/ft_signals.c \
				controllers/ft_history.c \
				cmd/ft_pwd.c \
				utils/ft_get_env.c utils/ft_mini_singleton.c

# SOURCE_B_FILES =

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

SOURCE_DIRS = cmd controllers utils

# SOURCES_B = $(addprefix $(SOURCES_PATH)/,$(SOURCE_B_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

OBJECTS_DIRS = $(addprefix $(OBJECTS_PATH)/,$(SOURCE_DIRS))

# OBJECTS_B = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_B_FILES)))

HEADERS_FILES = minishell.h
HEADERS = $(addprefix $(INCLUDES_PATH)/,$(HEADERS_FILES))

all:	$(LIBFT) $(NAME)

# bonus:	$(LIBFT) $(CHECKER_NAME)
valgrind: all
	valgrind --tool=memcheck --leak-check=full --track-origins=yes -s ./minishell


debug: set_debug_flag re
	echo "\033[0;31mdebbuger active"

set_debug_flag:
	$(eval CC = gcc -g -fsanitize=address)

$(NAME):	$(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(INCLUDES) $(LIBRARIES) -o $(NAME) 

# $(CHECKER_NAME): $(OBJECTS_B)
# 	$(CC) $(FLAGS) $(OBJECTS_B) $(INCLUDES) $(LIBRARIES) -o $(CHECKER_NAME)

$(LIBFT):
	$(MAKE_EXTERNAL) $(LIBFT_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADERS)
		$(SAFE_MAKEDIR) $(OBJECTS_PATH) $(OBJECTS_DIRS)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) clean

libft_fclean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

clean: libft_clean
	$(REMOVE) $(OBJECTS) $(OBJECTS_B)
	$(REMOVE) $(OBJECTS_PATH)

fclean: clean libft_fclean
	$(REMOVE) $(NAME) $(CHECKER_NAME)


re: fclean all

compress:
	tar -cf ./libs/libs.tar ./libs/*

extract:
	tar -xvf ./libs/libs.tar

.PHONY: all re libft_fclean libft_clean clean fclean bonus compress extract

