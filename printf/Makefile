# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 23:45:25 by mbui              #+#    #+#              #
#    Updated: 2020/11/10 15:00:19 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLGS = -Wall -Wextra -Werror
LIB_DIR = libft
SRCS_DIR = srcs/
SRCS =	ft_printf.c \
		parse.c \
		parse_utils.c \
		convert_length.c \
		print_percent.c \
		print_c.c \
		print_s.c \
		print_p.c \
		print_di.c \
		print_o.c \
		print_u.c \
		print_x.c \
		print_f.c \
		utils.c \
		utils2.c \

OBJS =	$(SRCS:.c=.o)

INCS = incs/libftprintf.h

all: $(NAME)

$(NAME): getlibft
	@cp $(LIB_DIR)/libft.a $(NAME)
	@$(CC) -c $(FLGS) $(addprefix $(SRCS_DIR)/,$(SRCS)) $(INCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) created.\n"

getlibft:
	@make -C $(LIB_DIR)

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(INCS).gch
	@make clean -C libft
	@printf "Objects and $(INCS).gch removed.\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft
	@printf "$(NAME) removed.\n"

re: fclean all

.PHONY: all clean fclean re
