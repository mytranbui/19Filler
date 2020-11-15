# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 12:49:35 by mbui              #+#    #+#              #
#    Updated: 2020/11/11 19:23:16 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLG = -Wall -Wextra -Werror
INC = ./inc/
SRC_PATH = src/
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
	  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
	  ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	  ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	  ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	  ft_tolower.c ft_toupper.c
BONUS = ft_abs.c ft_isspace.c ft_max.c ft_min.c ft_islower.c ft_isupper.c \
		ft_sqrt.c ft_strndup.c ft_isprime.c ft_itoa_base.c ft_utoa_base.c \
		 ft_strspn.c ft_strpbrk.c ft_strjoin_free.c free_tab.c tablen.c \
		get_next_line.c ft_swap.c sort_int_tab.c tabcpy.c nbwords.c \
		lstdel_tlist.c ft_listsize.c ft_intlen.c ft_dabs.c \
		ft_putnbrmax_fd.c ft_putnbrmax.c ft_putnbrumax_fd.c \
		ft_putnbrumax.c ft_intmaxabs.c ft_ldabs.c ft_llabs.c ft_pow.c ft_powl.c \
		ft_powf.c

OBJ = $(SRC:.c=.o) $(BONUS:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) -c $(FLG) $(SRC) $(BONUS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) created.\n"

clean:
	@rm -f $(OBJ) libft.h.gch
	@printf "objects and libft.h.gch removed.\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(NAME) removed.\n"

re: fclean all

.PHONY: clean fclean all re
