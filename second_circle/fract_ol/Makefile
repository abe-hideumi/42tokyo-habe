# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 16:34:10 by habe              #+#    #+#              #
#    Updated: 2025/10/05 16:24:52 by habe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = src_file/main.c\
	src_file/utils.c\
	src_file/init.c\
	src_file/mandelbrot.c\
	src_file/julia.c\
	src_file/operation.c\
	src_file/calculation.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -O2
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = ./minilibx-linux
MINILIBX_A = $(MINILIBX_DIR)/libmlx.a

INCLUDE = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/ft_printf -I$(MINILIBX_DIR)
LIBS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MINILIBX_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(MINILIBX_A):
	make -C $(MINILIBX_DIR)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
