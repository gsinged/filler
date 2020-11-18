/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:55:51 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:55:54 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_square_llu(int l, int base)
{
	unsigned long long	n;

	n = 1;
	while (l-- > 0)
		n *= base;
	return (n);
}

void				ft_printn_c(int n, int c)
{
	while (n--)
		write(1, &c, 1);
}

void				ft_putllu(unsigned long long n, int base, char up)
{
	int					len;
	unsigned long long	t;
	char				*s;

	if (up)
		s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		s = "0123456789abcdefghijklmnopqrstuvwxyz";
	len = ft_length_llu(n, base);
	t = ft_square_llu(len - 1, base);
	while (t)
	{
		up = n / t;
		n %= t;
		t /= base;
		write(1, s + up, 1);
	}
}

void				ft_putlli_s_p(unsigned long long n, t_frmt_spec *f, \
														int len, char sign)
{
	if (f->sign == 1)
		write(1, &sign, 1);
	else if (f->sign == 2)
	{
		write(1, "0", 1);
		write(1, &f->spec, 1);
	}
	if (f->precision > len)
		ft_printn_c(f->precision - len, '0');
	if (f->precision && len != 0)
		ft_putllu(n, ft_base(f), f->spec == 'X' ? 1 : 0);
}
