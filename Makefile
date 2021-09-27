# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 08:28:12 by lyuri-go          #+#    #+#              #
#    Updated: 2021/09/27 08:35:07 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	minitalk

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror
LIBRARIES = -L$(FT_PRINTF_PATH) -lft_printf
INCLUDES = -I$(INCLUDES_PATH) -I$(FT_PRINTF_PATH)

MAKE_EXTERNAL = make -C
REMOVE = rm -f
SAFE_MAKEDIR = mkdir -p

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs

FT_PRINTF = ft_printf
FT_PRINTF_PATH = ./$(LIBS_PATH)/$(FT_PRINTF)

SOURCE_FILES = main.c

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

HEADERS_FILES = minitalk.h
HEADERS_MINITALK = $(addprefix $(INCLUDES_PATH)/,$(HEADERS_FILES))

all:	$(NAME)

$(NAME):	ft_printf $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(INCLUDES) $(LIBRARIES) -o $(NAME)

ft_printf:
	$(MAKE_EXTERNAL) $(FT_PRINTF_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADERS_MINITALK)
		$(SAFE_MAKEDIR) $(OBJECTS_PATH)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

ft_printf_fclean:
	$(MAKE_EXTERNAL) $(FT_PRINTF_PATH) fclean

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean ft_printf_fclean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: ft_printf all re ft_printf_fclean clean fclean
