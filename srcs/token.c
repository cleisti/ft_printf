/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:21:32 by camilla           #+#    #+#             */
/*   Updated: 2020/04/15 16:03:34 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_shape_coords(t_token *token)
{
	int		y;
	int		x;
	int		i;
	
	token->shape->y = (int*)malloc(sizeof(int) * token->shape->size);
	token->shape->x = (int*)malloc(sizeof(int) * token->shape->size);
	y = 0;
	i = 0;
	while (token->area[y])
	{
		x = 0;
		while (token->area[y][x])
		{
			if (token->area[y][x] == '*')
			{
				// ft_printf("x: %d | y: %d | i: %d\n", x, y, i);
				token->shape->x[i] = x;
				token->shape->y[i] = y;
				// ft_printf("t.s.x[i]: %d | t.s.y[i]: %d\n", token.shape.x[i], token.shape.y[i]);
				i++;
			}
			x++;
		}
		y++;
	}
	// for (i = 0; i < token->shape.size; i++)
	// 	ft_printf("token.shape.x[i]: %d | token.shape.y[i]: %d\n", token->shape.x[i], token->shape.y[i]);
}
