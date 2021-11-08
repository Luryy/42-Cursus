# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 14:43:01 by lyuri-go          #+#    #+#              #
#    Updated: 2021/11/08 13:10:50 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror -pthread
INCLUDES = -I$(INCLUDES_PATH)

MAKE_EXTERNAL = make -C
REMOVE = rm -f
SAFE_MAKEDIR = mkdir -p

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes

SOURCE_FILES =	main.c ft_init_args.c ft_utils.c ft_philos.c ft_philo_death.c

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

HEADERS_FILES = philo.h
HEADERS = $(addprefix $(INCLUDES_PATH)/,$(HEADERS_FILES))

all:	$(LIBFT) $(NAME)

debug: set_debug_flag re
	echo "\033[0;31mdebbuger active"

set_debug_flag:
	$(eval CC = gcc -g)

$(NAME):	$(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME)

$(LIBFT):
	$(MAKE_EXTERNAL) $(LIBFT_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADERS)
		$(SAFE_MAKEDIR) $(OBJECTS_PATH)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all re clean fclean debug set_debug_flag

