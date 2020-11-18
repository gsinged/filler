/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:20:25 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/25 22:20:26 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char			s[11];
	int				i;
	unsigned int	nb;

	if (n == 0)
		ft_putchar('0');
	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		nb = n * -1;
	}
	else
		nb = n;
	while (nb > 0)
	{
		s[i] = '0' + nb % 10;
		nb /= 10;
		i++;
	}
	s[i] = '\0';
	while (i - 1 >= 0)
	{
		ft_putchar(s[i-- - 1]);
	}
}
