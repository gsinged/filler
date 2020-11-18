/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frc_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:55:22 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:55:25 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_karatsuba_n(unsigned long long *a, int n)
{
	int		i;
	int		m;

	i = 0;
	m = a[LENGTH_ARRAY - 1];
	while (i <= m)
	{
		a[m + n - i] = a[m - i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
	a[LENGTH_ARRAY - 1] += n;
}

static void		ft_frc_norm(unsigned long long *a, int n, int a_n, int i)
{
	unsigned long long	a_b;
	int					m;

	if (a_n == 0)
		a[LENGTH_ARRAY - 3] = n;
	else if (a_n < n)
	{
		a_n = n - a_n;
		if (a_n / 18)
		{
			ft_karatsuba_n(a, a_n / 18);
			a_n = a_n % 18;
		}
		a_b = ft_square_llu(a_n, 10);
		m = a[LENGTH_ARRAY - 1];
		while (i <= m && a_n)
		{
			a[m + 1 - i] += a[m - i] / (BASE / a_b);
			a[m - i] = a[m - i] % (BASE / a_b);
			a[m - i++] *= a_b;
		}
		if (a_n && a[m + 1])
			a[LENGTH_ARRAY - 1]++;
		a[LENGTH_ARRAY - 3] = n;
	}
}

static void		ft_frc_addition(unsigned long long *a, unsigned long long *b, \
													unsigned long long *res)
{
	int		n;

	n = a[LENGTH_ARRAY - 3] > b[LENGTH_ARRAY - 3] ? a[LENGTH_ARRAY - 3] : \
													b[LENGTH_ARRAY - 3];
	ft_frc_norm(a, n, a[LENGTH_ARRAY - 3], 0);
	ft_frc_norm(b, n, b[LENGTH_ARRAY - 3], 0);
	ft_bigint_addition(a, b, res);
	res[LENGTH_ARRAY - 3] = n;
}

void			ft_frc_a_addition(unsigned long long *a, unsigned long long *b)
{
	unsigned long long	res[LENGTH_ARRAY];

	ft_bzero(res, sizeof(res));
	ft_frc_addition(a, b, res);
	ft_bigint_copy(a, res);
}
