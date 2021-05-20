# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 18:19:26 by lyuri-go          #+#    #+#              #
#    Updated: 2021/05/20 18:46:22 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror

FILES	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_strlen.c ft_calloc.c ft_strdup.c

OBJ	=	$(FILES:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

%.o:	%.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
