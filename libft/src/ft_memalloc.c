/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:43:56 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/27 18:43:58 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*arr;

	if (!size)
		return (NULL);
	arr = (void*)malloc(sizeof(*arr) * size);
	if (!arr)
		return (NULL);
	return (ft_memset(arr, 0, size));
}
