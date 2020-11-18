/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 01:22:42 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/24 01:22:46 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if ((unsigned char*)dst < (unsigned char*)src)
	{
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char*)dst)[len - 1] = ((unsigned char*)src)[len - 1];
			len--;
		}
	}
	return (dst);
}
