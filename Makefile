# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camilla <camilla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 13:53:33 by camilla           #+#    #+#              #
#    Updated: 2020/04/15 18:47:30 by camilla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cleisti.filler
SRCS = srcs/main.c srcs/token.c srcs/placing.c srcs/testfuncs.c
OBJ = $(subst .c,.o,$(subst srcs/,,$(SRCS)))
INCL = -I ./includes/ -I ./ft_printf/includes/ -I ./ft_printf/libft/includes/
LIB = ./ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(SRCS) makelibft
	@gcc -c $(FLAGS) $(INCL) $(SRCS)
	@gcc -o $(NAME) $(OBJ) $(INCL) $(LIB)
	@mv $(NAME) ./resources/players
	
makelibft:
	@make -s fclean -C ./ft_printf && make -s -C ./ft_printf

clean:
	@rm -f $(OBJ)
	@make clean -C ./ft_printf

fclean: clean
	@rm -f resources/players/$(NAME)
	@make fclean -C ./ft_printf

re: fclean all

run: re
	resources/./filler_vm -p1 resources/players/cleisti.filler -p2 resources/players/carli.filler -v -f resources/maps/map00

test: re
	resources/players/./cleisti.filler