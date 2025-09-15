# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 12:40:15 by habe              #+#    #+#              #
#    Updated: 2025/09/15 20:06:58 by habe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = main.c\
	cmd_init.c\
	connect_pipe.c\
	free_utils.c\
	open_files.c\
	space_tab_split.c\
	utils.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

INCLUDE = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/ft_printf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
