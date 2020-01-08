/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:28:26 by cleisti           #+#    #+#             */
/*   Updated: 2020/01/08 15:10:34 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char c = 'K';

	ft_printf("ft_printf = character is: %c\n", c);
	printf("printf = character is: %c\n", c);
	return (0);
}
