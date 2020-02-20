/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:25:40 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/19 14:07:37 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_end(char *trav, t_args *ptr)
{
//	char	*united;
	char	*temp;
	int		len;
	int		i;

	len = ft_strlen(trav) - ptr->end;
	temp = ft_strndup(trav + ptr->end, len);
	ft_putstr(temp);
	i = ft_strlen(temp);
//	united = ft_strjoin(str, temp);
//	free(str);
	free(temp);
	return (i);
}

int		get_middle(char *trav, t_args *ptr)
{
//	char	*united;
	char	*temp;
	int		i;
	int		len;

	i = ptr->end;
//	printf("i: %d\n", i);
	while (trav[i] != '%')
		i++;
	len = i - ptr->end;
	temp = ft_strndup(trav + ptr->end, len);
	ft_putstr(temp);
	i = ft_strlen(temp);
//	united = ft_strjoin(str, temp);
//	free(str);
	free(temp);
//	printf("united: '%s'\n", united);
	return (i);
}

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
