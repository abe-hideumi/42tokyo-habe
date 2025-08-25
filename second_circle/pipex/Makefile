# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 12:40:15 by habe              #+#    #+#              #
#    Updated: 2025/08/25 13:14:07 by habe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = pipex_main.c\
	...

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
GNL_DIR = ./get_next_line

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a
GNL_A = $(GNL_DIR)/get_next_line.a

INCLUDE = -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)

$(NAME): $(OBJ) $(LIBFT_A) $(PRINTF_A) $(GNL_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(PRINTF_A) $(GNL_A) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)
$(PRINTF_A):
	make -C $(PRINTF_DIR)
$(GNL_A):
	make -C $(GNL_DIR)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(GNL_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)

re: fclean all

.PHONY: all clean fclean re
