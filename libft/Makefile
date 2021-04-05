# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 12:49:35 by mbui              #+#    #+#              #
#    Updated: 2020/12/15 16:40:31 by mbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLG = -Wall -Wextra -Werror
INC = ./inc/
SRC_PATH = src/
SRC = $(addprefix $(SRC_PATH)string/, $(SRCS_STRING)) \
	  $(addprefix $(SRC_PATH)stdlib/, $(SRCS_STDLIB)) \
	  $(addprefix $(SRC_PATH)stdio/, $(SRCS_STDIO)) \
      $(addprefix $(SRC_PATH)ctype/, $(SRCS_CTYPE)) \
      $(addprefix $(SRC_PATH)math/, $(SRCS_MATH)) \
	  $(addprefix $(SRC_PATH)lst/, $(SRCS_LST)) \
      $(addprefix $(SRC_PATH)bonus/, $(SRCS_BONUS)) \
      $(addprefix $(SRC_PATH)printf/, $(SRCS_PRINTF)) \

OBJ = $(SRCS_STRING:.c=.o) \
	  $(SRCS_STDLIB:.c=.o) \
	  $(SRCS_STDIO:.c=.o) \
	  $(SRCS_CTYPE:.c=.o) \
	  $(SRCS_MATH:.c=.o) \
	  $(SRCS_LST:.c=.o) \
	  $(SRCS_BONUS:.c=.o) \
	  $(SRCS_PRINTF:.c=.o) \

SRCS_STRING = ft_bzero.c \
			  ft_memset.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strlen.c \
			  ft_strcmp.c \
			  ft_strncmp.c \
			  ft_strcpy.c \
			  ft_strncpy.c \
			  ft_strcat.c \
			  ft_strncat.c \
			  ft_strlcat.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strstr.c \
			  ft_strnstr.c \
			  ft_strdup.c \
			  ft_strndup.c \
			  ft_strspn.c \
			  ft_strpbrk.c \
			  ft_memalloc.c \
			  ft_memdel.c \
			  ft_strdel.c\
			  ft_strclr.c \
			  ft_strequ.c \
			  ft_strnequ.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strsub.c \
			  ft_strtrim.c \
			  ft_strsplit.c \
			  ft_strnew.c \
			  ft_strjoin.c \
			  ft_strjoin_free.c \

SRCS_STDLIB = ft_atoi.c \
			  ft_itoa.c \
			  ft_itoa_base.c \
			  ft_utoa_base.c \
			  ft_abs.c \
			  ft_llabs.c \
			  ft_dabs.c \
			  ft_ldabs.c \
			  ft_intmaxabs.c \

SRCS_STDIO = ft_putchar.c \
			 ft_putchar_fd.c \
			 ft_putstr.c \
			 ft_putstr_fd.c \
			 ft_putendl.c \
			 ft_putendl_fd.c \
			 ft_putnbr.c \
			 ft_putnbr_fd.c \
			 ft_putnbrmax_fd.c \
			 ft_putnbrmax.c \
			 ft_putnbrumax_fd.c \
			 ft_putnbrumax.c \

SRCS_CTYPE = ft_isalnum.c \
			 ft_isalpha.c \
			 ft_isascii.c \
			 ft_isdigit.c \
			 ft_isprint.c \
			 ft_ispunct.c \
			 ft_isspace.c \
			 ft_islower.c \
			 ft_isupper.c \
			 ft_tolower.c \
			 ft_toupper.c \

SRCS_MATH =	ft_sqrt.c \
			ft_pow.c \
			ft_powl.c \
			ft_powf.c \

SRCS_LST = ft_lstnew.c \
		   ft_lstadd.c \
		   ft_lstdel.c \
		   ft_lstdelone.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_listsize.c \
		   lstdel_tlist.c \

SRCS_BONUS = ft_swap.c \
			ft_max.c \
			ft_min.c \
			ft_isprime.c \
			free_tab.c \
			tablen.c \
			get_next_line.c \
			sort_int_tab.c \
			tabcpy.c \
			nbwords.c \
			ft_intlen.c \
			ft_pos_i.c \

SRCS_PRINTF = ft_printf.c \
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
			  print_f2.c \
			  utils.c \
			  utils2.c \

all: $(NAME)

$(NAME):
	@$(CC) -c $(FLG) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32m$(NAME) \033[0m\033[32mcreated.\033[0m"

clean:
	@rm -f $(OBJ) libft.h.gch
	@echo "\033[31mobject files of \033[0m\033[1;31m$(NAME)\033[0m \033[31mremoved.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m$(NAME) \033[0m\033[31mremoved.\033[0m"

re: fclean all

.PHONY: clean fclean all re
