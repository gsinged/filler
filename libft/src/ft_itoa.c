/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 04:40:22 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/28 04:40:24 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_ln(int n)
{
	long int	nb;
	int			ln;

	nb = n;
	if (n < 0)
		nb *= -1;
	ln = 0;
	while (nb > 0)
	{
		ln++;
		nb /= 10;
	}
	return (ln);
}

static char	*ft_fill(long int nb, int ln, int neg)
{
	int		i;
	char	*s;

	if (!(s = (char*)malloc(sizeof(*s) * (ln + neg + 1))))
		return (NULL);
	i = 0;
	while (i < ln)
	{
		s[i] = '0' + nb % 10;
		nb /= 10;
		i++;
	}
	if (neg)
	{
		s[i] = '-';
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_expand(char *s)
{
	int		ln;
	int		i;
	char	c;

	ln = ft_strlen(s);
	i = 0;
	while (i < ln / 2)
	{
		c = s[i];
		s[i] = s[ln - i - 1];
		s[ln - i - 1] = c;
		i++;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char		*s;
	int			ln;
	long int	nb;
	int			neg;

	if (n == 0)
		return (ft_fill(0, 1, 0));
	nb = n;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		nb *= -1;
	}
	ln = ft_ln(n);
	if (!(s = ft_fill(nb, ln, neg)))
		return (NULL);
	return (ft_expand(s));
}
