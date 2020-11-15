# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 17:37:13 by mbui              #+#    #+#              #
#    Updated: 2020/11/15 17:37:42 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mbui.filler
CC = gcc
FLG = -Wall -Wextra -Werror
SRC_DIR = src/
SRC = check_input.c store.c solve.c main.c 
LIB = libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): getlibft
	@$(CC) $(FLG) -c $(addprefix $(SRC_DIR)/,$(SRC))
	@$(CC) $(FLG) $(OBJ) $(LIB) -o $(NAME)
	@echo "$(NAME) created.\n"

getlibft:
	@make -C libft

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@printf "objects of filler removed.\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@printf "$(NAME) removed.\n"

re: fclean all

.PHONY: clean fclean all re
