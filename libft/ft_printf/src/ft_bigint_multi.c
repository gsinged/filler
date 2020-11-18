/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:49:14 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:49:17 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_multi_l_norm(unsigned long long *p, int i)
{
	int		j;

	j = LENGTH_ARRAY - 3;
	while (i <= j)
	{
		if (p[i] > BASE)
		{
			p[i] -= BASE;
			p[i + 1]++;
			i++;
		}
		else
			i = j + 1;
	}
}

static void	ft_multi_l_base_a(unsigned long long *x, unsigned long long *y, \
							unsigned long long *r)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			r[i + j] += y[i] * x[j];
			j++;
		}
		i++;
	}
}

static void	ft_multi_l_base_b(unsigned long long *r)
{
	unsigned int		i;

	i = 0;
	while (i < 3)
	{
		if (r[i] > LBASE)
		{
			r[i + 1] += r[i] / LBASE;
			r[i] = r[i] % LBASE;
		}
		i++;
	}
}

static void	ft_multi_l_base(unsigned long long a, unsigned long long b, \
									unsigned long long *res, unsigned int g)
{
	unsigned long long	x[2];
	unsigned long long	y[2];
	unsigned long long	r[4];

	ft_bzero(x, sizeof(x));
	ft_bzero(y, sizeof(y));
	ft_bzero(r, sizeof(r));
	x[0] = a % LBASE;
	x[1] = a / LBASE;
	y[0] = b % LBASE;
	y[1] = b / LBASE;
	ft_multi_l_base_a(x, y, r);
	ft_multi_l_base_b(r);
	res[g] += (r[1] * LBASE) + r[0];
	if (r[2] || r[3])
	{
		res[g + 1] += r[3] * LBASE + r[2];
		ft_multi_l_norm(res, g + 1);
	}
}

void		ft_bigint_multi(unsigned long long *a, unsigned long long *b, \
									unsigned long long *res)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i <= b[LENGTH_ARRAY - 1])
	{
		j = 0;
		while (j <= a[LENGTH_ARRAY - 1])
		{
			ft_multi_l_base(a[j], b[i], res, i + j);
			j++;
		}
		i++;
	}
	ft_multi_b_norme(res, a[LENGTH_ARRAY - 1] + b[LENGTH_ARRAY - 1] + 2);
	res[LENGTH_ARRAY - 2] = a[LENGTH_ARRAY - 2] + b[LENGTH_ARRAY - 2];
}
