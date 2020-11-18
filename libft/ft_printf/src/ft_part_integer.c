/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:56:24 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:56:26 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_two_power(unsigned int p)
{
	unsigned long long	n;

	if (p < 64)
	{
		n = 1;
		n = n << p;
		return (n);
	}
	return (0);
}

static void					ft_p_i_equal_parts(unsigned long long *p, \
													unsigned int pow)
{
	unsigned long long	b[LENGTH_ARRAY];
	unsigned int		p_pow;

	p_pow = p[LENGTH_ARRAY - 2];
	ft_bzero(b, sizeof(b));
	if ((pow / p_pow) % 2)
	{
		ft_bigint_copy(b, p);
		ft_p_i_equal_parts(p, pow - p_pow);
		ft_bigint_a_multi(p, b);
	}
	else if ((pow / p_pow) > 3)
	{
		ft_bigint_copy(b, p);
		ft_bigint_a_multi(p, b);
		ft_p_i_equal_parts(p, pow);
	}
	else
	{
		ft_bigint_copy(b, p);
		ft_bigint_a_multi(p, b);
	}
}

static void					ft_piece_int_p0(unsigned long long *p, \
						unsigned int pow)
{
	if (pow <= 59)
	{
		p[0] = ft_two_power(pow);
		p[LENGTH_ARRAY - 2] = pow;
	}
	else
	{
		p[0] = ft_two_power(59);
		p[LENGTH_ARRAY - 2] = 59;
		ft_piece_int(p, pow);
	}
}

void						ft_piece_int(unsigned long long *p, \
											unsigned int pow)
{
	unsigned int		rem;
	unsigned int		p_pow;
	unsigned long long	b[LENGTH_ARRAY];

	p_pow = p[LENGTH_ARRAY - 2];
	ft_bzero(b, sizeof(b));
	if (!p[LENGTH_ARRAY - 2])
		ft_piece_int_p0(p, pow);
	else if ((pow / p_pow) > 1)
	{
		rem = pow % p_pow;
		ft_p_i_equal_parts(p, pow - rem);
		ft_piece_int(p, pow);
	}
	else if (pow - p_pow)
	{
		ft_piece_int(b, pow - p_pow);
		ft_bigint_a_multi(p, b);
	}
}

int							ft_part_integer(unsigned long long hf, int exp, \
												unsigned long long *bgi)
{
	unsigned long long	p[LENGTH_ARRAY];
	unsigned int		i;

	if (exp < 0)
		return (0);
	if (exp < 64)
	{
		bgi[0] = hf;
		return (0);
	}
	i = 0;
	ft_bzero(p, sizeof(p));
	while (i < 64)
	{
		if (((hf << (63 - i)) >> 63))
		{
			ft_piece_int(p, exp - (63 - i));
			ft_bigint_a_addition(bgi, p);
		}
		i++;
	}
	return (0);
}
