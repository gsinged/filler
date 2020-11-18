/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part_fraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:56:08 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:56:11 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_p_f_equal_parts(unsigned long long *p, unsigned int pow)
{
	unsigned long long	b[LENGTH_ARRAY];
	unsigned int		p_pow;

	p_pow = p[LENGTH_ARRAY - 2];
	ft_bzero(b, sizeof(b));
	if ((pow / p_pow) % 2)
	{
		ft_bigint_copy(b, p);
		ft_p_f_equal_parts(p, pow - p_pow);
		ft_bigint_a_multi(p, b);
	}
	else if ((pow / p_pow) > 3)
	{
		ft_bigint_copy(b, p);
		ft_bigint_a_multi(p, b);
		ft_p_f_equal_parts(p, pow);
	}
	else
	{
		ft_bigint_copy(b, p);
		ft_bigint_a_multi(p, b);
	}
}

static void		ft_piece_fraction(unsigned long long *p, unsigned int pow)
{
	unsigned int		rem;
	unsigned int		p_pow;
	unsigned long long	b[LENGTH_ARRAY];

	p_pow = p[LENGTH_ARRAY - 2];
	ft_bzero(b, sizeof(b));
	if (!p[LENGTH_ARRAY - 2])
	{
		p[0] = 5;
		p[LENGTH_ARRAY - 2] = 1;
		ft_piece_fraction(p, pow);
	}
	else if ((pow / p_pow) > 1)
	{
		rem = pow % p_pow;
		ft_p_f_equal_parts(p, pow - rem);
		ft_piece_fraction(p, pow);
	}
	else if (pow - p_pow)
	{
		ft_piece_fraction(b, pow - p_pow);
		ft_bigint_a_multi(p, b);
	}
}

int				ft_part_fraction(unsigned long long hf, int exp, \
											unsigned long long *frc)
{
	unsigned long long	p[LENGTH_ARRAY];
	unsigned long long	b[LENGTH_ARRAY];
	unsigned int		i;

	if (hf == 0)
		return (0);
	if (exp < 0)
		exp *= -1;
	else
		exp = 1;
	ft_bzero(p, sizeof(p));
	ft_bzero(b, sizeof(b));
	i = 0;
	while (i < 64)
	{
		if ((hf << i) >> 63)
		{
			ft_piece_fraction(p, exp + i);
			ft_bigint_copy(b, p);
			b[LENGTH_ARRAY - 3] = b[LENGTH_ARRAY - 2];
			ft_frc_a_addition(frc, b);
		}
		i++;
	}
	return (0);
}
