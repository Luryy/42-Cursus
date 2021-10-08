# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 08:22:29 by lyuri-go          #+#    #+#              #
#    Updated: 2021/09/27 08:40:01 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft_printf.a

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror

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

SOURCE_FILES =	ft_controller.c ft_flags.c ft_handle.c ft_helpers_p.c ft_helpers.c ft_print_c.c \
				ft_printf.c ft_print_int.c ft_print_p.c ft_print_percent.c ft_print_s.c \
				ft_print_u.c ft_print_width.c ft_print_x.c ft_verify.c

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

bonus: all

.PHONY: libft all re libft_fclean clean fclean bonus
