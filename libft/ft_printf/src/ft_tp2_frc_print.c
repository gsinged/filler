/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp2_frc_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:13 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:59:16 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_frc_putllu_n_p(unsigned long long n, int len, int p)
{
	unsigned long long	t;
	int					i;
	char				c;

	t = ft_square_llu(len, 10);
	n = n % t;
	t /= 10;
	while (t && p)
	{
		i = n / t;
		n %= t;
		t /= 10;
		c = '0' + i;
		write(1, &c, 1);
		p--;
	}
}

static void		ft_frc_p_print_l(unsigned long long *frc, int p, int i)
{
	while (p > 0)
	{
		if (p - 18 >= 0)
		{
			ft_bg_putllu_18(frc[i]);
			p -= 18;
		}
		else
		{
			ft_frc_putllu_n_p(frc[i], 18, p);
			p -= p;
		}
		i--;
	}
}

static void		ft_frc_p_print(unsigned long long *frc, int p)
{
	int		i;
	int		n;

	i = (frc[LENGTH_ARRAY - 3] / 18) - 1;
	n = frc[LENGTH_ARRAY - 3] % 18;
	if (n)
	{
		i++;
		if (p - n >= 0)
		{
			ft_frc_putllu_n(frc[i], n);
			p -= n;
		}
		else
		{
			ft_frc_putllu_n_p(frc[i], n, p);
			p -= p;
		}
		i--;
	}
	ft_frc_p_print_l(frc, p, i);
}

static void		ft_frc_notp_print(unsigned long long *frc)
{
	int		i;
	int		n;

	i = (frc[LENGTH_ARRAY - 3] / 18) - 1;
	n = frc[LENGTH_ARRAY - 3] % 18;
	if (n)
	{
		i++;
		ft_frc_putllu_n(frc[i], n);
		i--;
	}
	while (i >= 0)
	{
		ft_bg_putllu_18(frc[i]);
		i--;
	}
}

int				ft_frc_print(unsigned long long *frc, int p, char sh)
{
	int		n;

	if (!p && sh)
		write(1, ".", 1);
	if (!p)
		return (0);
	write(1, ".", 1);
	n = frc[LENGTH_ARRAY - 3];
	if (n <= p)
	{
		ft_frc_notp_print(frc);
		ft_printn_c(p - n, '0');
	}
	else
		ft_frc_p_print(frc, p);
	return (0);
}
