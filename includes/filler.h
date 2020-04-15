/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:59:57 by camilla           #+#    #+#             */
/*   Updated: 2020/04/15 17:32:22 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# include <stdlib.h>
# include "../ft_printf/includes/ft_printf.h"
# include "../ft_printf/libft/includes/libft.h"

typedef struct	s_player
{
	int			num;
	char		pawn;
	char		e_pawn;
}				t_player;

typedef struct	s_shape
{
	int			size;
	int			*y;
	int			*x;
}				t_shape;

typedef struct	s_token
{
	char		**area;
	int			y_size;
	int			x_size;
	t_shape		*shape;
}				t_token;

typedef struct s_coords
{
	int				x;
	int				y;
	int				heat;
	struct s_coords	*next;
}				t_coords;


// typedef struct	s_map
// {
// 	int			y_size;
// 	int			x_size;
// 	char		**board;
// 	int			total;
// 	int			occupied;
// 	int			own;
// 	int			enemy;
// 	int			*area_y;
// 	int			*area_x;
// 	int			y_0[2];
// 	int			y_max[2];
// 	int			x_0[2];
// 	int			x_max[2];
// 	int			*e_area_y;
// 	int			*e_area_x;
// }				t_map;


typedef struct	s_filler
{
	t_token		*token;
	// t_map		*map;
	int			y_size;
	int			x_size;
	char		**board;
	int			total;
	int			occupied;
	int			own;
	int			enemy;
	int			*area_y;
	int			*area_x;
	int			y_0[2];
	int			y_max[2];
	int			x_0[2];
	int			x_max[2];
	int			*e_area_y;
	int			*e_area_x;
}				t_container;


int		filler(void);

void	get_shape_coords(t_token *token);

void	place(t_container *filler, t_player *player);

// void	print_gathered_info(t_container *filler);

#endif