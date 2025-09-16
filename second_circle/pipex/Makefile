# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 12:40:15 by habe              #+#    #+#              #
#    Updated: 2025/09/16 13:14:16 by habe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = src_file/main.c\
	src_file/cmd_init.c\
	src_file/connect_pipe.c\
	src_file/free_utils.c\
	src_file/open_files.c\
	src_file/space_tab_split.c\
	src_file/utils.c

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
