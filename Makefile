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
	   srcs/open_funcs1.c srcs/open_f.c srcs/refine_str.c srcs/helper_funcs.c \
	   srcs/len_mods.c srcs/helper_funcs2.c srcs/open_di.c srcs/open_o.c srcs/open_u.c \
	   srcs/open_x.c
OBJ = $(subst .c,.o,$(subst srcs/,,$(SRCS)))
INCL = -I includes/ -I libft/includes/
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
LIBRARY = ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): makelibft
	@ cp $(LIBFT) $(NAME)
	@ gcc $(FLAGS) $(INCL) -c $(SRCS)
	@ $(LIBRARY)
	@ ranlib $(NAME)

makelibft:
	@ make -C libft/ fclean && make -C libft/

clean:
	@ rm -f $(OBJ)
	@ make -C libft/ clean

fclean: clean
	@ rm -f $(NAME)
	@ make -C libft/ fclean

re: fclean all

run: re
	gcc ../testmains/main.c $(NAME) -I libft/includes -I includes
	./a.out

debug: re
	gcc -G $(FLAGS) main.c $(NAME) -I libft/includes -I includes -o debug