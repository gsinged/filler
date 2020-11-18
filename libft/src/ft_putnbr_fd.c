/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:25:17 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/28 00:25:20 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			s[11];
	int				i;
	unsigned int	nb;

	if (n == 0)
		ft_putchar_fd('0', fd);
	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(s[i-- - 1], fd);
	}
}
