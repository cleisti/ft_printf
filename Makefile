# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 11:33:50 by marvin            #+#    #+#              #
#    Updated: 2019/12/25 11:33:50 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = /srcs/ft_printf.c
OBJ = $(subst .c,.o,$(SRCS))
CC = gcc -Wall -Wextra -Werror
LIBRARY = ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): SRCS
	$(CC) -c $(SRCS)
	$(LIBRARY)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all