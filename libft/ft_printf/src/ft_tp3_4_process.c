/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp3_4_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:00:17 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 16:00:18 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_tp3_w(t_frmt_spec *f, char c)
{
	if (f->left)
	{
		write(1, &c, 1);
		ft_printn_c(f->width - 1, ' ');
	}
	else
	{
		if (f->zero == 1)
		{
			ft_printn_c(f->width - 1, '0');
			write(1, &c, 1);
		}
		else
		{
			ft_printn_c(f->width - 1, ' ');
			write(1, &c, 1);
		}
	}
}

int			ft_tp3_process(t_frmt_spec *f, va_list arg)
{
	char	c;

	c = (char)va_arg(arg, int);
	if (f->width)
	{
		ft_tp3_w(f, c);
		return (f->width);
	}
	else
		write(1, &c, 1);
	return (1);
}

static void	ft_tp4_w(t_frmt_spec *f, char *s, int len)
{
	if (f->left)
	{
		ft_printn_c(f->precision - len, ' ');
		write(1, s, len);
		ft_printn_c(f->width - f->precision, ' ');
	}
	else
	{
		if (f->zero == 1)
		{
			ft_printn_c(f->width - len, '0');
			write(1, s, len);
		}
		else
		{
			ft_printn_c(f->width - len, ' ');
			write(1, s, len);
		}
	}
}

int			ft_tp4_process(t_frmt_spec *f, va_list arg)
{
	char	*s;
	int		len;

	s = va_arg(arg, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f->prec && len > f->precision && f->precision >= 0)
		len = f->precision;
	else
		f->precision = len;
	if (f->width > f->precision)
	{
		ft_tp4_w(f, s, len);
		return (f->width);
	}
	write(1, s, len);
	return (len);
}
