# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 11:33:50 by marvin            #+#    #+#              #
#    Updated: 2020/01/07 16:33:53 by cleisti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = sources/ft_printf.c
OBJ = $(subst .c,.o,$(SRCS))
INCL = includes/
CC = gcc -Wall -Wextra -Werror
LIBRARY = ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) -c $(SRCS) -I $(INCL)
	$(LIBRARY)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
