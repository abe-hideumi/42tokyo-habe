“…# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 14:01:27 by habe              #+#    #+#              #
#    Updated: 2025/07/07 14:34:31 by habe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = push_swap_main.c\
		put_in_nbr.c\
		atoi_checker.c\
		lst_utils.c\

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(NAME)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(OBJ)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
