/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp2_rounding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:00:07 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 16:00:09 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_round_exist_a(unsigned long long *a, char more, \
												unsigned long long j_b)
{
	unsigned int	n;
	size_t			k;
	int				j;

	k = a[LENGTH_ARRAY - 4];
	j = a[LENGTH_ARRAY - 5];
	n = a[k] % 10;
	a[k] /= 10;
	a[k] *= (j_b * 10);
	if (n < 5)
		return (0);
	else if ((n > 5) || (n == 5 && more))
		return (1);
	if (j == 18)
		n = a[k + 1] % 10;
	else
		n = (a[k] % (j_b * 100)) / (j_b * 10);
	if (n % 2)
		return (1);
	else
		return (0);
}

static int		ft_round_exist(unsigned long long *a, int rem, char more, \
												unsigned long long j_b)
{
	size_t	k;
	int		j;

	k = (rem / 18) - 1;
	if ((j = rem % 18))
		if (k)
			k++;
	!j ? j = 18 : 0;
	a[LENGTH_ARRAY - 4] = k;
	a[LENGTH_ARRAY - 5] = j;
	while (j_b < k)
	{
		a[j_b] ? more = 1 : 0;
		a[j_b++] = 0;
	}
	j_b = ft_square_llu(j - 1, 10);
	a[k] % j_b ? more = 1 : 0;
	a[k] /= j_b;
	return (ft_round_exist_a(a, more, j_b));
}

static int		ft_round(unsigned long long *a, int k, unsigned long long j)
{
	if (j == 18 && ++k)
		j = 0;
	j = ft_square_llu(j, 10);
	a[k] += j;
	while (k <= (int)a[LENGTH_ARRAY - 1] + 1)
	{
		if (a[k] >= BASE)
		{
			a[k] -= BASE;
			a[k + 1]++;
			k++;
		}
		else
			break ;
	}
	if (k > (int)a[LENGTH_ARRAY - 1])
		return (1);
	else if (k == (int)a[LENGTH_ARRAY - 1])
	{
		j = a[LENGTH_ARRAY - 3] % 18;
		j = ft_square_llu(j, 10);
		if (a[k] / j)
			return (1);
	}
	return (0);
}

static int		ft_round_p_zero(unsigned long long *a, int bgi)
{
	if (a[0] < 5)
		return (0);
	else if ((a[0] > 5) || (a[0] == 5 && bgi))
		return (1);
	return (0);
}

int				ft_rounding(unsigned long long *a, int p, int bgi)
{
	if (p >= (int)a[LENGTH_ARRAY - 3])
		return (0);
	if (a[LENGTH_ARRAY - 3] == 1 && p == 0)
		return (ft_round_p_zero(a, bgi));
	if (ft_round_exist(a, a[LENGTH_ARRAY - 3] - p, 0, 0))
		return (ft_round(a, a[LENGTH_ARRAY - 4], a[LENGTH_ARRAY - 5]));
	return (0);
}
