/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp1_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:58:29 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:58:34 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_base(t_frmt_spec *f)
{
	if (f->spec == 'd' || f->spec == 'i' || f->spec == 'u')
		return (10);
	else if (f->spec == 'o')
		return (8);
	else if (f->spec == 'x' || f->spec == 'X')
		return (16);
	return (0);
}

static void		ft_tp1_print_l(unsigned long long n, t_frmt_spec *f, int len, \
														char sign)
{
	if (f->left)
	{
		ft_putlli_s_p(n, f, len, sign);
		ft_printn_c(f->width - f->precision - f->sign, ' ');
	}
	else
	{
		if (f->zero == 1)
		{
			if (f->sign == 1)
				write(1, &sign, 1);
			else if (f->sign == 2)
			{
				write(1, "0", 1);
				write(1, &f->spec, 1);
			}
			ft_printn_c(f->width - f->precision - f->sign, '0');
			ft_putllu(n, ft_base(f), f->spec == 'X' ? 1 : 0);
		}
		else
		{
			ft_printn_c(f->width - f->precision - f->sign, ' ');
			ft_putlli_s_p(n, f, len, sign);
		}
	}
}

static void		ft_tp1_print(unsigned long long n, t_frmt_spec *f, int len, \
														char sign)
{
	if (f->width > f->precision + f->sign)
		ft_tp1_print_l(n, f, len, sign);
	else
		ft_putlli_s_p(n, f, len, sign);
}

int				ft_tp1_process(t_frmt_spec *f, va_list arg, int base)
{
	unsigned long long	n;
	int					len;
	char				sign;

	f->length > 8 ? f->length = 8 : 0;
	n = ft_take_llu_sign(f, arg, &sign);
	len = ft_length_llu(n, base);
	if (f->prec == 1 && f->precision == 0 && n == 0)
		len = 0;
	else if ((f->prec == 1 && f->precision < len) || f->prec == 0)
		f->precision = len;
	if (f->spec == 'o' && f->sharp == 1 && f->precision == len && \
												(f->prec != 0 || n != 0))
		f->precision++;
	else if ((f->spec == 'x' || f->spec == 'X') && f->sharp == 1 && n == 0)
		f->sign = 0;
	else if ((f->spec == 'x' || f->spec == 'X') && f->sharp == 1)
		f->sign = 2;
	else if (!sign && f->sign)
		sign = f->plus ? '+' : ' ';
	ft_tp1_print(n, f, len, sign);
	if (f->width < f->precision + f->sign)
		f->width = f->precision + f->sign;
	return (f->width);
}
