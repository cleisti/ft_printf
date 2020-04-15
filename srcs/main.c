/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:59:04 by camilla           #+#    #+#             */
/*   Updated: 2020/04/15 18:36:04 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		get_player_num(t_player *player)
{
	char	*line;
	
	get_next_line(0, &line);
	if (line && !(ft_strncmp(line, "$$$ exec p1", 11)))
	{
		player->num = 1;
		player->pawn = 'O';
		player->e_pawn = 'X';
	}
	else if (line && !(ft_strncmp(line, "$$$ exec p2", 11)))
	{
		player->num = 2;
		player->pawn = 'X';
		player->e_pawn = 'O';
	}
	else
		return ;
	// ft_printf("num: %d | pawn: %c | e_pawn: %c\n", player->num, player->pawn, player->e_pawn);
	ft_strdel(&line);
}

static void		read_board(t_container *filler, char *line)
{
	int		i;

	filler->y_size = ft_atoi(ft_strchr(line, ' '));
	filler->x_size = ft_atoi(ft_strchr(line + 8, ' '));
	filler->board = ft_2dnew(filler->y_size, filler->x_size);
	get_next_line(0, &line);
	ft_strdel(&line);
	i = 0;
	while (i < filler->y_size)
	{
		get_next_line(0, &line);
		ft_strcpy(filler->board[i], line + 4);
		ft_strdel(&line);
		i++;
	}
	// ft_printf("\nmap->y_size: %d | map->x_size: %d\n", filler->y_size, filler->x_size);
	// ft_print_2darr(filler->board);
	// ft_printf("%s\n", line);
}

int				count_pieces(char *str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '*')
			ret++;
		i++;
	}
	return (ret);
}

static void		read_token(t_container *filler, char *line)
{
	int		i;

	filler->token = malloc(sizeof(t_token));
	filler->token->shape = malloc(sizeof(t_shape));
	filler->token->y_size = ft_atoi(ft_strchr(line, ' '));
	filler->token->x_size = ft_atoi(ft_strchr(line + 7, ' '));
	filler->token->area = ft_2dnew(filler->token->y_size, filler->token->x_size);
	i = 0;
	// ft_printf("\nfiller->token->y_size: %d | filler->token->x_size: %d\n", filler->token->y_size, filler->token->x_size);
	while (i < filler->token->y_size)
	{
		ft_strdel(&line);
		get_next_line(0, &line);
		ft_strcpy(filler->token->area[i], line);
		filler->token->shape->size += count_pieces(filler->token->area[i]);
		i++;
	}
	// ft_printf("%s\n", line);
	// ft_printf("filler->token->shape.size: %d\n", filler->token->shape.size);
	get_shape_coords(filler->token);
	// ft_printf("\nfiller->token->y_size: %d | filler->token->x_size: %d | shape.size: %d\n", filler->token->y_size, filler->token->x_size, filler->token->shape.size);
	// ft_print_2darr(filler->token->area);
	// for (i = 0; i < filler->token->shape.size; i++)
	// 	ft_printf("filler->token->shape.x[i]: %d | filler->token->shape.y[i]: %d\n", filler->token->shape.x[i], filler->token->shape.y[i]);
}

/*
** TRY LATER TO MAKE FUNCTION THAT TAKES BOTH MAP AND TOKEN INFO:
*/
// static void		read_input(t_container *filler, char *line, int offset)
// {
// 	int		i;
// 	int		x;
// 	int		y;

// 	i = (offset > 0) ? 1 : 0;
// 	y = ft_atoi(strchr(line, ' '));
// 	x = ft_atoi(strchr(line + 7 + i, ' '));	
// }

// void			loop(t_container filler)
// {
// 	while (1)
// 	{
// 		if (ft_strncmp(line, "Plateau", 7) == 0)
// 			read_map(filler.map, line);
// 		if (ft_strncmp(line, "Piece", 5) == 0)
// 			read_token(filler.token, line);
// 		function to find place
//		function to give coords
// 	}
// }

int				main(void)
{
	t_container	*filler;
	t_player	*player;
	char		*line;

	if (!(filler = (t_container*)malloc(sizeof(t_container)))
		|| !(player = (t_player*)malloc(sizeof(t_player))))
		return (0);
	get_player_num(player);
	// loop(filler);
	while (get_next_line(0, &line) > -1)
	{
		if (line && ft_strncmp(line, "Plateau", 7) == 0)
			read_board(filler, line);
		else if (line && ft_strncmp(line, "Piece", 5) == 0)
		{
			read_token(filler, line);
			place(filler, player);
		}
		// ft_strdel(&line);
		// else
		// 	place(filler);
		// print_gathered_info(filler);
	}
}