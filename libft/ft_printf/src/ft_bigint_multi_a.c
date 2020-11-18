/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multi_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:49:26 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:49:39 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_multi_b_norme(unsigned long long *res, int j)
{
	int		i;
	int		m;

	m = 0;
	i = 0;
	while (i < j)
	{
		if (res[i] >= BASE)
		{
			res[i + 1] += res[i] / BASE;
			res[i] = res[i] % BASE;
		}
		if (res[i])
			m = i;
		i++;
	}
	res[LENGTH_ARRAY - 1] = m;
}

void	ft_bigint_a_multi(unsigned long long *a, unsigned long long *b)
{
	unsigned long long	res[LENGTH_ARRAY];

	ft_bzero(res, sizeof(res));
	ft_bigint_multi(a, b, res);
	ft_bigint_copy(a, res);
}
