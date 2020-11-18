/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:48:42 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:48:50 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bigint_copy(unsigned long long *a, unsigned long long *b)
{
	unsigned int	i;

	i = 0;
	while (i < LENGTH_ARRAY)
	{
		a[i] = b[i];
		i++;
	}
}

static void	ft_bigint_addition_a(unsigned long long *res, unsigned int len)
{
	unsigned int	i;
	unsigned int	m;

	i = 0;
	m = 0;
	while (i <= len + 1)
	{
		if (res[i] >= BASE)
		{
			res[i] -= BASE;
			res[i + 1]++;
		}
		if (res[i])
			m = i;
		i++;
	}
	res[LENGTH_ARRAY - 1] = m;
}

void		ft_bigint_addition(unsigned long long *a, unsigned long long *b, \
								unsigned long long *res)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = (a[LENGTH_ARRAY - 1] > b[LENGTH_ARRAY - 1] ? \
				a[LENGTH_ARRAY - 1] : b[LENGTH_ARRAY - 1]) + 1;
	while (i <= len)
	{
		res[i] = a[i] + b[i];
		i++;
	}
	ft_bigint_addition_a(res, len);
}

void		ft_bigint_a_addition(unsigned long long *a, unsigned long long *b)
{
	unsigned long long	res[LENGTH_ARRAY];

	ft_bzero(res, sizeof(res));
	ft_bigint_addition(a, b, res);
	ft_bigint_copy(a, res);
}
