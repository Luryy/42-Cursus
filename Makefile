# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 08:29:17 by lyuri-go          #+#    #+#              #
#    Updated: 2021/06/14 08:36:07 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	get_next_line.a

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror

FILES	=	get_next_line.c get_next_line_utils.c

BONUS	=	get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ	=	$(FILES:.c=.o)

OBJ_B	=	$(BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

%.o:	%.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ) $(OBJ_B)

fclean: clean
		rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(OBJ_B)
	ar rc $(NAME) $(OBJ_B)
