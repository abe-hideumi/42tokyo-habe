# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 12:44:26 by habe              #+#    #+#              #
#    Updated: 2025/09/01 12:08:13 by habe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = \
	push_swap_main.c\
	put_in_nbr.c\
	ps_atoi_checker.c\
	utils.c\
	utils2.c\
	push_to_b.c\
	push_to_a.c\
	small_sort.c\
	operation_push.c\
	operation_swap.c\
	operation_rotate.c\
	operation_r_rotate.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

INCLUDE = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/ft_printf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
