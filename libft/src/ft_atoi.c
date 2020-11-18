/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:39:21 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/25 21:39:23 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative_check(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int			ft_atoi(const char *str)
{
	long int	res;
	int			i;
	int			neg;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if ((neg = ft_negative_check(*str)) < 0)
		str++;
	else if (*str == '+')
		str++;
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		i++;
		str++;
	}
	if (neg < 0)
		res *= neg;
	return (res);
}
