/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:04:04 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/07 18:04:22 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		validate_modifier(char *trav, int i, t_args *ptr)
{
	char	*valids;
	int		x;

	valids = "cspdiouxXf%lhjtzqL. #0+-*123456789";
	x = 0;
	while (valids[x])
	{
		if (valids[x] == trav[i])
			return (1);
		x++;
	}
	if (x > 33 || trav[i] == '\0')
	{
		ptr->mod = 10;
		ptr->end = i;
	}
	return (0);
}
