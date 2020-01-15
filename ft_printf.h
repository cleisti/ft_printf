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

typedef struct			s_args
{
	char				*str;
	int					modifier;
	int					flag;
	int					precision;
	int					len_mod;
	int					len;
	int					end_index;
	struct s_args		*next;
}						t_args;

typedef char *(*func_ptr)(va_list);

enum	e_flags
{
	HASH = '#',
	ZERO = '0',
	MINUS = '-',
	PLUS = '+',
	SPACE = ' ',

};

int		ft_printf(const char *format, ...);

char	*parse_format_str(va_list args, char *trav);
int		print_string(char *str);

char	*open_c(va_list args);
char	*open_s(va_list args);

char	*get_argument(t_args *ptr, va_list args);
char	*parse_arguments(char *trav, va_list args, t_args *start);

char	*check_for_percentage_signs(char *str);
char	*remove_percentage(char *str, int i);
char	*get_middle(char *str, char *trav, t_args *ptr);
char	*get_end(char *str, char *trav, t_args *ptr);

t_args	*arguments_to_list(char *trav, t_args *start);
t_args	*put_to_list(char *trav, int i, t_args *ptr);
void	initialize_t_args(t_args *ptr);

int		check_modifier(char *trav, int i, t_args *ptr);
void	check_length_modifier(char *trav, int i, t_args *ptr);
void	check_precision(char *trav, int i, t_args *ptr);
void	check_flags(char *trav, int i, t_args *ptr);

#endif