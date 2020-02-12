/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:04:04 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/10 12:59:53 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		validate_modifier(char *trav, int i)
{
	char	*valids;
	int		x;

	valids = "lhjtzqL. #0+-*123456789";
	x = 0;
	while (valids[x])
	{
		if (valids[x] == trav[i])
			return (1);
		x++;
	}
	return (0);
}
