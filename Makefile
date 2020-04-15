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
	   srcs/open_c.c srcs/open_s.c srcs/open_p.c srcs/open_di.c srcs/open_o.c \
	   srcs/open_u.c srcs/open_x.c srcs/open_f.c srcs/helpfuncs.c srcs/len_mods.c
OBJ = $(subst .c,.o,$(subst srcs/,,$(SRCS)))
INCL = -I ./includes/ -I ./libft/includes/
FLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a
LIBRARY = ar rc $(NAME) $(OBJ)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	@ make makelibft
	@ cp $(LIBFT) ./$(NAME)
	@ gcc $(FLAGS) $(INCL) -c $(SRCS)
	@ $(LIBRARY)
	@ ranlib $(NAME)

makelibft:
	@ make -s fclean -C ./libft && make -s -C ./libft

clean:
	@ rm -f $(OBJ)
	@ make -s clean -C ./libft

fclean: clean
	@ rm -f $(NAME)
	@ make -s fclean -C ./libft

re: fclean all

run: re
	gcc ../testmains/main.c $(NAME) -I libft/includes -I includes
	./a.out