# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 08:22:29 by lyuri-go          #+#    #+#              #
#    Updated: 2021/06/30 08:36:19 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC	=	gcc
FLAGS	=	# -Wall -Wextra -Werror

ARCHIVE_AND_INDEX = ar -rc
MAKE_EXTERNAL = make -C
REMOVE = rm -f
SAFE_MAKEDIR = mkdir -p

SOURCES_PATH = ./sources
OBJECTS_PATH = ./objects
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs

LIBFT = libft
LIBFT_PATH = $(LIBS_PATH)/$(LIBFT)
COPY_LIBFT = cp $(LIBFT_PATH)/libft.a

SOURCE_FILES = ft_printf.c
SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

INCLUDES_FILES = ft_printf.h
INCLUDES = $(addprefix $(INCLUDES_PATH)/,$(INCLUDES_FILES))

all:	$(NAME)

$(NAME):	libft $(OBJECTS) $(INCLUDES)
	$(ARCHIVE_AND_INDEX) $(NAME) $(OBJECTS)

libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH)
	$(COPY_LIBFT) ./$(NAME)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(INCLUDES)
		$(SAFE_MAKEDIR) $(OBJECTS_PATH)
		$(CC) $(FLAGS) -I $(INCLUDES_PATH) -c $< -o $@

libft_fclean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean libft_fclean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: libft all re libft_fclean clean fclean
