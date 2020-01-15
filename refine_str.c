/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:25:40 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/15 11:05:48 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_end(char *str, char *trav, t_args *ptr)
{
	char *temp;
	int len;

	len = ft_strlen(trav) - ptr->end_index;
	temp = ft_strndup(trav + ptr->end_index, len);
	str = ft_strjoin(str, temp);
	return (str);
}

char	*get_middle(char *str, char *trav, t_args *ptr)
{
	char *temp;
	int i;
	int len;

	i = ptr->end_index;
	while (trav[i] != '%')
		i++;
	len = i - ptr->end_index;
	temp = ft_strndup(trav + ptr->end_index, len);
	str = ft_strjoin(str, temp);
	return (str);
}

char	*remove_percentage(char *str, int i)
{
	char *temp;

	temp = ft_strnew(ft_strlen(str) - 1);
	ft_strncpy(temp, str, i);
	ft_strjoin(temp, str + i + 1);
	return (temp);
}

char	*check_for_percentage_signs(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			str = remove_percentage(str, i);
		i++;
	}
	return (str);
}
