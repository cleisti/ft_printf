/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:28:45 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/27 12:55:53 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_pow(int num, int topow)
{
	if (topow == 0)
		return (1);
	else if (topow % 2 == 0)
		return (ft_pow(num, topow / 2) * ft_pow(num, topow / 2));
	else
		return (num * ft_pow(num, topow / 2) * ft_pow(num, topow / 2));
}
