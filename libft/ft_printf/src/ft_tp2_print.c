/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp2_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:38 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:59:40 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bg_putllu_18(unsigned long long n)
{
	unsigned long long	t;
	int					i;
	char				c;

	t = 100000000000000000;
	while (t)
	{
		i = n / t;
		n %= t;
		t /= 10;
		c = '0' + i;
		write(1, &c, 1);
	}
}

void		ft_frc_putllu_n(unsigned long long n, int len)
{
	unsigned long long	t;
	int					i;
	char				c;

	t = ft_square_llu(len, 10);
	n = n % t;
	t /= 10;
	while (t)
	{
		i = n / t;
		n %= t;
		t /= 10;
		c = '0' + i;
		write(1, &c, 1);
	}
}

void		ft_bigint_print(unsigned long long *bgi)
{
	int	i;

	i = bgi[LENGTH_ARRAY - 1];
	ft_putllu(bgi[i], 10, 0);
	i--;
	while (i >= 0)
	{
		ft_bg_putllu_18(bgi[i]);
		i--;
	}
}
