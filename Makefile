# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 13:19:17 by marvin            #+#    #+#              #
#    Updated: 2020/01/27 17:56:33 by cleisti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/check_funcs.c srcs/list_funcs.c srcs/parse_args.c \
	   srcs/open_funcs1.c srcs/open_funcs2.c srcs/refine_str.c srcs/helper_funcs.c \
	   srcs/len_mods.c
OBJ = $(subst .c,.o,$(subst srcs/,,$(SRCS)))
INCL = -I includes/ -I libft/includes/
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
LIBRARY = ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@ make -C libft/ fclean && make -C libft/
	@ cp $(LIBFT) $(NAME)
	@ gcc $(FLAGS) $(INCL) -c $(SRCS)
	@ $(LIBRARY)
	@ ranlib $(NAME)

clean:
	@ rm -f $(OBJ)
	@ make -C libft/ clean

fclean: clean
	@ rm -f $(NAME)
	@ make -C libft/ fclean

re: fclean all

run: re
	gcc $(FLAGS) main.c $(NAME) -I libft/includes
	./a.out
