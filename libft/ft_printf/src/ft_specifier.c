/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:57:36 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:57:37 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_tp6_process(t_frmt_spec *f)
{
	if (f->width > 1)
	{
		if (f->left)
		{
			write(1, "%", 1);
			ft_printn_c(f->width - 1, ' ');
		}
		else
		{
			if (f->zero)
				ft_printn_c(f->width - 1, '0');
			else
				ft_printn_c(f->width - 1, ' ');
			write(1, "%", 1);
		}
		return (f->width);
	}
	write(1, "%", 1);
	return (1);
}

static int	ft_spec_process(t_frmt_spec *f, va_list arg)
{
	if (f->type == 1)
		return (ft_tp1_process(f, arg, ft_base(f)));
	if (f->type == 2)
	{
		!f->prec ? f->precision = 6 : 0;
		return (ft_tp2_process(f, arg));
	}
	else if (f->type == 3)
		return (ft_tp3_process(f, arg));
	else if (f->type == 4)
		return (ft_tp4_process(f, arg));
	else if (f->type == 5)
		return (ft_tp5_process(f, arg));
	else if (f->type == 6)
		return (ft_tp6_process(f));
	return (0);
}

char		*ft_specifier(char *s, va_list arg, t_frmt_spec *f, size_t *n)
{
	int		len;

	ft_frmt_spec_0(f);
	s = ft_spec_parser(s, f, arg);
	len = ft_spec_process(f, arg);
	if (len == -1)
		f->error = 1;
	else
		*n += len;
	return (s);
}
