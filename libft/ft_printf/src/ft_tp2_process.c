/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp2_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:52 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:59:53 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_tp2_print_l(unsigned long long *bgi, unsigned long long *frc, \
											t_frmt_spec *f, t_fnum *fn)
{
	if (f->left)
	{
		if (f->sign)
			write(1, &fn->sign, 1);
		ft_bigint_print(bgi);
		ft_frc_print(frc, f->precision, f->sharp);
		ft_printn_c(f->width - f->length - f->sharp - f->sign, ' ');
	}
	else
	{
		if (f->zero)
		{
			if (f->sign)
				write(1, &fn->sign, 1);
			ft_printn_c(f->width - f->length - f->sharp - f->sign, '0');
		}
		else
		{
			ft_printn_c(f->width - f->length - f->sharp - f->sign, ' ');
			if (f->sign)
				write(1, &fn->sign, 1);
		}
		ft_bigint_print(bgi);
		ft_frc_print(frc, f->precision, f->sharp);
	}
}

static void	ft_tp2_print(unsigned long long *bgi, unsigned long long *frc, \
											t_frmt_spec *f, t_fnum *fn)
{
	f->length = ft_bgi_length(bgi);
	f->length += f->precision;
	f->precision > 0 ? f->sharp = 1 : 0;
	fn->sign ? f->sign = 1 : 0;
	fn->sign ? fn->sign = '-' : 0;
	if (!fn->sign && f->sign)
		fn->sign = f->plus ? '+' : ' ';
	if (f->width > f->length + f->sharp + f->sign)
		ft_tp2_print_l(bgi, frc, f, fn);
	else
	{
		if (f->sign)
			write(1, &fn->sign, 1);
		ft_bigint_print(bgi);
		ft_frc_print(frc, f->precision, f->sharp);
		f->width = f->length + f->sharp + f->sign;
	}
}

static void	ft_tp2_inf(t_frmt_spec *f, t_fnum *fn, char *str)
{
	if (f->width > 3 + f->sign)
	{
		if (f->left)
		{
			if (f->sign)
				write(1, &fn->sign, 1);
			write(1, str, 3);
			ft_printn_c(f->width - 3 - f->sign, ' ');
		}
		else
		{
			ft_printn_c(f->width - 3 - f->sign, ' ');
			if (f->sign)
				write(1, &fn->sign, 1);
			write(1, str, 3);
		}
	}
	else
	{
		if (f->sign)
			write(1, &fn->sign, 1);
		write(1, str, 3);
		f->width = 3 + f->sign;
	}
}

static void	ft_tp2_nan_inf(t_frmt_spec *f, t_fnum *fn)
{
	fn->sign ? f->sign = 1 : 0;
	fn->sign ? fn->sign = '-' : 0;
	if (!fn->sign && f->sign)
		fn->sign = f->plus ? '+' : ' ';
	if (fn->mnts)
	{
		f->sign = 0;
		ft_tp2_inf(f, fn, "nan");
	}
	else
		ft_tp2_inf(f, fn, "inf");
}

int			ft_tp2_process(t_frmt_spec *f, va_list arg)
{
	t_fnum				*fn;
	unsigned long long	hf[2];
	unsigned long long	bgi[LENGTH_ARRAY];
	unsigned long long	frc[LENGTH_ARRAY];

	if (!(fn = ft_fnum_new()))
		return (-1);
	if (f->length == sizeof(long double))
		ft_get_number(fn, va_arg(arg, long double), hf);
	else
		ft_get_number(fn, (long double)va_arg(arg, double), hf);
	if (fn->exp == 16384)
		ft_tp2_nan_inf(f, fn);
	else
	{
		ft_bzero(bgi, sizeof(bgi));
		ft_bzero(frc, sizeof(frc));
		ft_part_fraction(hf[1], fn->exp, frc);
		ft_part_integer(hf[0], fn->exp, bgi);
		if ((ft_rounding(frc, f->precision, bgi[0] % 2)))
			ft_bgi_round(bgi);
		ft_tp2_print(bgi, frc, f, fn);
	}
	free(fn);
	return (f->width);
}
