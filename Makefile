# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 13:19:17 by marvin            #+#    #+#              #
#    Updated: 2020/01/10 13:19:17 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
SRC = main.c ft_printf.c

LIB = libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)

clean: 
	rm -rf *.swp

fclean: clean
	rm -rf $(NAME)

re: fclean all