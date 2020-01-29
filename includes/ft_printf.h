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

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

// con -> len_mod | len_mod ->prec_w

typedef struct			s_args
{
	int					mod;
	int					flag[5];
	int					w;
	int					prec;
	int					prec_w;
	int					len_mod;
	int					neg;
	int					x;
	int					len;
	int					null;
	int					start;
	int					end;
	struct s_args		*next;
}						t_args;

typedef char *(*func_ptr)(va_list, t_args *);

int		ft_printf(const char *format, ...);
char	*parse_format_str(va_list args, char *trav);
int		print_string(char *str);

char	*open_c(va_list args, t_args *ptr);
char	*open_s(va_list args, t_args *ptr);
char	*open_p(va_list args, t_args *ptr);
char	*open_di(va_list args, t_args *ptr);

char	*open_o(va_list args, t_args *ptr);
char	*open_u(va_list args, t_args *ptr);
char	*open_x(va_list args, t_args *ptr);
char	*open_f(va_list args, t_args *ptr);

char	*open_h(va_list args, t_args *ptr);
char	*open_hh(va_list args, t_args *ptr);
char	*open_l(va_list args, t_args *ptr);
char	*open_ll(va_list args, t_args *ptr);
char	*open_cl(va_list args, t_args *ptr);

char	*convert(va_list args, t_args *ptr);
char	*get_argument(va_list args, t_args *ptr);
char	*parse_arguments(char *trav, va_list args, t_args *start);

char	*check_for_percentage_signs(char *str);
char	*remove_percentage(char *str, int i);
char	*get_middle(char *str, char *trav, t_args *ptr);
char	*get_end(char *str, char *trav, t_args *ptr);

t_args	*arguments_to_list(char *trav, t_args *start);
t_args	*put_to_list(char *trav, int i, t_args *ptr);
void	initialize_t_args(t_args *ptr);
void	free_list(t_args *ptr);

int		check_modifier(char *trav, int i, t_args *ptr);
int		check_conversion(char *trav, int i, t_args *ptr);
int		check_precision(char *trav, int i, t_args *ptr);
int		check_flags(char *trav, int i, t_args *ptr);
int		check_width(char *trav, int i, t_args *ptr);

char	*set_str(int w, char c);
char	*base_string(long long u, int base, t_args *ptr);
char	*plus_space(char *get, int plus, int space);
char	*add_zeros(char *get, int len, int neg);
char	*set_width(char *get, t_args *ptr, int neg);

#endif