/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp5_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:00:25 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 16:00:28 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_tp5_w(t_frmt_spec *f, unsigned long long n, int len, char sign)
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
			write(1, "0", 1);
			write(1, &f->spec, 1);
			ft_printn_c(f->width - f->precision - f->sign, '0');
			ft_putllu(n, 16, 0);
		}
		else
		{
			ft_printn_c(f->width - f->precision - f->sign, ' ');
			ft_putlli_s_p(n, f, len, sign);
		}
	}
}

int			ft_tp5_process(t_frmt_spec *f, va_list arg)
{
	unsigned long long	n;
	int					len;
	char				sign;

	f->spec = 'x';
	f->length = 8;
	f->sharp = 1;
	n = ft_take_llu_sign(f, arg, &sign);
	len = ft_length_llu(n, 16);
	if (f->prec == 1 && f->precision == 0 && n == 0)
		len = 0;
	else if ((f->prec == 1 && f->precision < len) || f->prec == 0)
		f->precision = len;
	f->sign = 2;
	if (f->width > f->precision + f->sign)
		ft_tp5_w(f, n, len, sign);
	else
		ft_putlli_s_p(n, f, len, sign);
	if (f->width < f->precision + f->sign)
		f->width = f->precision + f->sign;
	return (f->width);
}
