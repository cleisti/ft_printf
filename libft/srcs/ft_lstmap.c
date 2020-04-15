/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:09:07 by cleisti           #+#    #+#             */
/*   Updated: 2019/11/06 12:01:57 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *new;

	if (!(lst))
		return (NULL);
	if (!(ptr = f(lst)))
		return (NULL);
	new = ptr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ptr->next = f(lst)))
			return (NULL);
		ptr = ptr->next;
	}
	return (new);
}
