# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/04/26 18:18:28 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC_PATH = project
SRC_NAME = main.c ft_readfile.c ft_checkfile.c ft_createmap.c ft_fillmap.c \
		   ft_putcolor.c ft_createttab.c
OBJ_PATH = project
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

.PHONY: all, clean, fclean, re 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(LIBFT):
	$(MAKE) -C ./libft/

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./libft/ clean
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft/ fclean

re: fclean all
