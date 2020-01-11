/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 23:06:23 by marvin            #+#    #+#             */
/*   Updated: 2019/12/25 23:06:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct		s_args
{
	char			*str;
	char			c;
	struct s_args	*next;
}					t_args;

int		ft_printf(const char *format, ...);
char	*parse_str(va_list args, char *trav);
char	*concenate_strings(char *ptr, char *trav, size_t i);
char	*check_args(va_list args, char *trav, size_t i);
int		print_string(char *full_str);

#endif