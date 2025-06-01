# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babe <habe@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 16:21:00 by habe              #+#    #+#              #
#    Updated: 2025/05/30 15:46:00 by babe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FILES = atoi\
			bzero\
			calloc\
			isalnum\
			isalpha\
			isascii\
			isdigit\
			isprint\
			itoa\
			memchr\
			memcmp\
			memcpy\
			memmove\
			memset\
			putchar_fd\
			putendl_fd\
			putnbr_fd\
			putstr_fd\
			split\
			strchr\
			strdup\
			striteri\
			strjoin\
			strlcat\
			strlcpy\
			strlen\
			strmapi\
			strncmp\
			strnstr\
			strrchr\
			strtrim\
			substr\
			tolower\
			toupper\

SRC = $(addprefix ft_, $(addsuffix .c, $(SRC_FILES)))
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
