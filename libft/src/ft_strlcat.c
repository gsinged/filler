/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:24:24 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/24 22:24:26 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size > len1)
		dst = ft_strncat(dst, src, size - len1 - 1);
	else
		return (len2 + size);
	return (len1 + len2);
}
