#!/bin/sh

gcc -Wall -Werror -Wextra -c ft_putchar.c ft_strcmp.c ft_swap.c ft_putstr.c ft_strlen.c
ar -rc libft.a *.o
ranlib libft.a
rm -f *.o
