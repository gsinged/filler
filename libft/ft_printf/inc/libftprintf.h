/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:01:07 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 16:01:08 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include "floatnumber.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_format_specifier {
	int				type;
	int				width;
	int				precision;
	int				length;
	char			plus;
	char			space;
	char			sharp;
	char			left;
	char			zero;
	char			spec;
	char			prec;
	char			sign;
	char			error;
}					t_frmt_spec;

int					ft_printf(const char *format, ...);

/*
** s_format_specifier
*/

t_frmt_spec			*ft_new_frmt_spec(void);
void				ft_frmt_spec_0(t_frmt_spec *f);

/*
** Parser
*/

char				*ft_specifier(char *s, va_list arg, \
										t_frmt_spec *f, size_t *n);
char				*ft_spec_parser(char *s, t_frmt_spec *f, va_list arg);
void				ft_spec_exclusion(t_frmt_spec *f);
int					ft_tp1_process(t_frmt_spec *f, va_list arg, int base);
int					ft_base(t_frmt_spec *f);
void				ft_printn_c(int n, int c);
unsigned long long	ft_square_llu(int l, int base);
void				ft_putlli_s_p(unsigned long long n, t_frmt_spec *f, \
										int len, char sign);
void				ft_putllu(unsigned long long n, int base, char up);
unsigned long long	ft_take_llu_sign(t_frmt_spec *f, va_list arg, char *sign);
int					ft_length_llu(unsigned long long n, int base);
int					ft_tp2_process(t_frmt_spec *f, va_list arg);
int					ft_tp3_process(t_frmt_spec *f, va_list arg);
int					ft_tp4_process(t_frmt_spec *f, va_list arg);

int					ft_tp5_process(t_frmt_spec *f, va_list arg);
#endif
