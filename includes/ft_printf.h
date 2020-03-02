/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:08:30 by cleisti           #+#    #+#             */
/*   Updated: 2020/02/24 17:48:44 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

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
	int					rm_p;
	int					str;
	int					start;
	int					end;
	struct s_args		*next;
}						t_args;

typedef int				(*t_func_ptr)(va_list args, t_args *ptr);
typedef char			*(*t_len_mod)(va_list args, t_args *ptr);

int						print_string(char *str);
int						parse_format_str(va_list args, char *trav);
int						ft_printf(const char *format, ...);

int						open_percentage(t_args *ptr);
int						open_c(va_list args, t_args *ptr);
int						open_s(va_list args, t_args *ptr);
int						open_p(va_list args, t_args *ptr);
int						open_di(va_list args, t_args *ptr);
int						open_o(va_list args, t_args *ptr);
int						open_u(va_list args, t_args *ptr);
int						open_x(va_list args, t_args *ptr);
int						open_f(va_list args, t_args *ptr);
char					*open_h(va_list args, t_args *ptr);
char					*open_hh(va_list args, t_args *ptr);
char					*open_l(va_list args, t_args *ptr);
char					*open_ll(va_list args, t_args *ptr);

char					*convert(va_list args, t_args *ptr);
int						print_argument(va_list args, t_args *ptr);
int						parse_args(char *trav, va_list args, t_args *start);
int						print_end(char *trav, t_args *ptr);
int						print_middle(char *trav, t_args *ptr);
int						validate_modifier(char *trav, int i);
char					*zero_x(char *get, int mod);

void					free_list(t_args *ptr);
void					validate(t_args *ptr);
void					initialize_t_args(t_args *ptr);
t_args					*put_to_list(char *trav, int i, t_args *ptr);
t_args					*arguments_to_list(char *trav, t_args *start);

int						check_modifier(char *trav, int i, t_args *ptr);
int						check_conversion(char *trav, int i, t_args *ptr);
int						check_precision(char *trav, int x, t_args *ptr);
int						check_flags(char *trav, int i, t_args *ptr);
int						check_width(char *trav, int i, t_args *ptr);

#endif
