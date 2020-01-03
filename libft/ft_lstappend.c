/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:42:45 by cleisti           #+#    #+#             */
/*   Updated: 2019/12/02 14:56:07 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstend(t_list **alst, t_list *new)
{
	t_list *ptr;

	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
