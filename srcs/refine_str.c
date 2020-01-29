/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:25:40 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/28 10:41:59 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_end(char *str, char *trav, t_args *ptr)
{
	char	*united;
	char	*temp;
	int		len;

	len = ft_strlen(trav) - ptr->end;
	temp = ft_strndup(trav + ptr->end, len);
	united = ft_strjoin(str, temp);
	free(str);
	free(temp);
	return (united);
}

char	*get_middle(char *str, char *trav, t_args *ptr)
{
	char	*united;
	char	*temp;
	int		i;
	int		len;

	i = ptr->end;
	while (trav[i] != '%')
		i++;
	len = i - ptr->end;
	temp = ft_strndup(trav + ptr->end, len);
	united = ft_strjoin(str, temp);
	ft_strdel(&str);
	ft_strdel(&temp);
	return (united);
}

char	*remove_percentage(char *str, int i)
{
	char *new;
	char *temp;

	new = ft_strnew(ft_strlen(str) - 1);
	temp = ft_strdup(str + i + 1);
	ft_strncpy(new, str, i);
	new = ft_strjoin(new, temp);
	return (new);
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
