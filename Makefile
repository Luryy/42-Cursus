# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 08:28:12 by lyuri-go          #+#    #+#              #
#    Updated: 2021/09/28 17:21:10 by lyuri-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	minitalk
SERVER = server
CLIENT = client

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

SERVER_PATH = server
SOURCE_FILES_SERVER = server.c
SOURCES_SERVER = $(addprefix $(SOURCES_PATH)/$(SERVER_PATH)/,$(SOURCE_FILES_SERVER))
OBJECTS_SERVER = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES_SERVER)))

CLIENT_PATH = client
SOURCE_FILES_CLIENT = client.c
SOURCES_CLIENT = $(addprefix $(SOURCES_PATH)/$(CLIENT_PATH)/,$(SOURCE_FILES_CLIENT))
OBJECTS_CLIENT = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES_CLIENT)))

HEADERS_FILES = minitalk.h
HEADERS_MINITALK = $(addprefix $(INCLUDES_PATH)/,$(HEADERS_FILES))

all:	$(NAME)

$(NAME):	ft_printf $(SERVER) $(CLIENT)

$(SERVER): $(OBJECTS_SERVER)
	$(CC) $(FLAGS) $(OBJECTS_SERVER) $(INCLUDES) $(LIBRARIES) -o $(SERVER)

$(CLIENT): $(OBJECTS_CLIENT)
	$(CC) $(FLAGS) $(OBJECTS_CLIENT) $(INCLUDES) $(LIBRARIES) -o $(CLIENT)

ft_printf:
	$(MAKE_EXTERNAL) $(FT_PRINTF_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/*/%.c $(HEADERS_MINITALK)
		$(SAFE_MAKEDIR) $(OBJECTS_PATH)
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

ft_printf_fclean:
	$(MAKE_EXTERNAL) $(FT_PRINTF_PATH) fclean

clean:
	$(REMOVE) $(OBJECTS_SERVER) $(OBJECTS_CLIENT)

fclean: clean ft_printf_fclean
	$(REMOVE) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: ft_printf all re ft_printf_fclean clean fclean
