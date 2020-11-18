/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:00:06 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/23 20:00:08 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	ct;
	char	*tmp;

	ct = 0;
	tmp = b;
	if (len == 0)
		return (b);
	while (ct < len)
	{
		tmp[ct] = (unsigned char)c;
		ct++;
	}
	return (tmp);
}
