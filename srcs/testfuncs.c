/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camilla <camilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 13:40:38 by camilla           #+#    #+#             */
/*   Updated: 2020/04/15 17:34:02 by camilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	print_gathered_info(t_container *filler, t_player *player)
{
	int i;

	ft_printf("\nPlayer number: '%d'\nToken own: '%c'\nToken enemy: '%c'\n\n", player->num, player->pawn, player->e_pawn);
	ft_printf("filler->map.y_size: %d\nfiller->map.x_size: %d\nfiller->map.board:\n", filler->y_size, filler->x_size);
	ft_print_2darr(filler->board);
	ft_printf("\nfiller->token.y_size: %d\nfiller->token.x_size: %d\nfiller->token.area:\n", filler->token->y_size, filler->token->x_size);
	ft_print_2darr(filler->token->area);
	ft_printf("\nfiller->token.shape.size: %d\n", filler->token->shape->size);
	for (i = 0; i < filler->token->shape->size; i++)
		ft_printf("filler->token.shape.x[i]: %d | filler->token.shape.y[i]: %d\n", filler->token->shape->x[i], filler->token->shape->y[i]);
}
