/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:44:14 by camilla           #+#    #+#             */
/*   Updated: 2020/04/15 18:35:16 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		count_space(t_container *filler, char c)
{
	int		y;
	int		x;
	int		count;
	int		pawn;
	
	y = 0;
	count = 0;
	pawn = (c != '.') ? 1 : 0;
	while (y < filler->y_size)
	{
		x = 0;
		while (x < filler->x_size)
		{
			if (filler->board[y][x] == c)
				count++;
			else if (pawn && ft_toupper(filler->board[y][x] == c))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void		conquered_area(t_container *filler, t_player *player, int y, int x)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	filler->area_y = (int*)malloc(sizeof(int) * filler->own);
	filler->area_x = (int*)malloc(sizeof(int) * filler->own);
	filler->e_area_y = (int*)malloc(sizeof(int) * filler->enemy);
	filler->e_area_x = (int*)malloc(sizeof(int) * filler->enemy);
	while (filler->board[y])
	{
		x = 0;
		while (filler->board[x])
		{
			if (filler->board[y][x] == player->pawn)
			{
				filler->area_y[j] = y;
				filler->area_x[j] = x;
				j++;
			}
			else if (filler->board[y][x] == player->e_pawn)
			{
				filler->e_area_y[i] = y;
				filler->e_area_y[i] = x;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void		status(t_container *filler)
{
	int		i;

	i = 0;
	filler->y_0[0] = filler->area_y[i];
	filler->y_max[0] = filler->area_y[i];
	filler->x_0[0] = filler->area_x[i];
	filler->x_max[0] = filler->area_x[i];
	while (i < filler->own)
	{
		if (filler->area_y[i] < filler->y_0[0])
			filler->y_0[0] = filler->area_y[i];
		if (filler->area_y[i] > filler->y_max[0])
			filler->y_max[0] = filler->area_y[i];
		if (filler->area_x[i] < filler->x_0[0])
			filler->x_0[0] = filler->area_x[i];
		if (filler->area_x[i] > filler->x_max[0])
			filler->x_max[0] = filler->area_x[i];
		i++;
	}
}

// static void		prioritize_direction(t_map *map)
// {
	
// }

static void		map_stats(t_container *filler, t_player *player)
{
	// ft_printf("pawn: %c | e_pawn: %c\n", player->pawn, player->e_pawn);
	filler->total = filler->x_size * filler->y_size;
	filler->occupied = filler->total - count_space(filler, '.');
	// ft_printf("filler->o: %d | pawn: %c | e_pawn: %c\n", filler->occupied, player->pawn, player->e_pawn);
	filler->own = count_space(filler, player->pawn);
	filler->enemy = count_space(filler, player->e_pawn);
	conquered_area(filler, player, 0, 0);
	status(filler);
	// prioritize_direction(filler);
}

static int		check_overflow(t_container *filler, t_shape *shape, int y, int x)
{
	int		i;
	
	i = 0;
	while (i < shape->size)
	{
		if (y + shape->y[i] >= filler->y_size || x + shape->x[i] >= filler->x_size)
			return (0);
		i++;
	}
	return (1);
}

static int		fit(t_container *filler, t_player *player, int y, int x)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (!(check_overflow(filler, filler->token->shape, y, x)))
		return (0);
	while (i < filler->token->shape->size)
	{
		if (filler->board[y + filler->token->shape->y[i]][x + filler->token->shape->x[i]] == '.')
			i++;
		else if (check == 0 && filler->board[y + filler->token->shape->y[i]][x + filler->token->shape->x[i]]
				== player->pawn)
		{
			check = 1;
			i++;
		}
		else
			return (0);
	}
	if (check)
		return (1);
	return (0);
}

// static int		count_distance(int)

static int		wall_distance(t_container *filler, t_shape *shape, int y, int x)
{
	int		i;
	int		heat;

	i = 0;
	heat = 0;
	while (i < shape->size)
	{
		// ft_printf("wall dist\n");
		if (y + shape->y[i] == 0 && heat < filler->y_0[0])
			heat = filler->y_0[0];
		if (x + shape->x[i] == 0 && heat < filler->x_0[0])
			heat = filler->x_0[0];
		if (y + shape->y[i] == filler->y_size && heat < filler->y_max[0])
			heat = filler->y_max[0];
		if (x + shape->x[i] == filler->x_size && heat < filler->x_max[0])
			heat = filler->x_max[0];
		i++;	
	}
	return (heat);
}

static void		count_heat(t_container *filler, t_coords *coords, int y, int x)
{
	coords->y = y;
	coords->x = x;
	coords->heat += wall_distance(filler, filler->token->shape, y, x);
	if (!(coords->next = (t_coords*)malloc(sizeof(t_coords))))
		return ;
}

void			print_coordinates(t_coords *coords)
{
	t_coords	*ptr;
	int			hot;
	int			y;
	int			x;

	hot = -1;
	y = -1;
	x = -1;
	// ft_printf("PRINT\n");
	while (coords)
	{
		ptr = coords;
		if (coords->heat > hot)
		{
			hot = coords->heat;
			y = coords->y;
			x = coords->x;
		}
		coords = coords->next;
		free(ptr);
	}
	ft_printf("%d %d\n", y, x);
}

void		free_structs(t_container *filler)
{
	// free(filler->token->area);
	// free(filler->token->shape->y);
	// free(filler->token->shape->x);
	// free(filler->token);
	// free(filler->board);
	// free(filler->area_y);
	// free(filler->area_x);
	// free(filler->e_area_y);
	// free(filler->e_area_x);
	free(filler);
}

void		place(t_container *filler, t_player *player)
{
	t_coords	*start;
	t_coords	*coords;
	int			y;
	int			x;
	
	map_stats(filler, player);
	if(!(start = (t_coords*)malloc(sizeof(t_coords))))
		return ;
	coords = start;
	y = 0;
	while (y < filler->y_size)
	{
		x = 0;
		while (x < filler->x_size)
		{
			if (fit(filler, player, y, x))
			{
				count_heat(filler, coords, y, x);
				coords = coords->next;
			}
			x++;
		}
		y++;
	}
	print_coordinates(start);
	// free_structs(filler);
}
