/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp2_assist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:00 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:59:03 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_number(t_fnum *fn, long double ld, unsigned long long *hf)
{
	unsigned long long	*llu;

	llu = (unsigned long long *)&ld;
	fn->mnts = llu[0];
	fn->exp = (llu[1] & MASK_EXP) - MASK_EXP_SHIFT;
	fn->sign = ((llu[1] & MASK_SIGN) >> 15);
	if (fn->exp >= 0 && fn->exp < 64)
	{
		hf[0] = fn->mnts >> (63 - fn->exp);
		hf[1] = fn->mnts << (fn->exp + 1);
	}
	else if (fn->exp >= 64)
	{
		hf[0] = fn->mnts;
		hf[1] = 0;
	}
	else
	{
		hf[0] = 0;
		hf[1] = fn->mnts;
	}
}

void	ft_bgi_round(unsigned long long *bgi)
{
	unsigned long long	b[LENGTH_ARRAY];

	ft_bzero(b, sizeof(b));
	b[0] = 1;
	ft_bigint_a_addition(bgi, b);
}

int		ft_bgi_length(unsigned long long *bgi)
{
	int					len;
	int					k;
	unsigned long long	t;

	k = bgi[LENGTH_ARRAY - 1];
	len = 18;
	t = BASE / 10;
	while (t)
	{
		if (bgi[k] / t)
			break ;
		len--;
		t /= 10;
	}
	len += k * 18;
	return (len);
}
