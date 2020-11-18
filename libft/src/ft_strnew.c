/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:44:21 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/27 18:44:23 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	while (size + 1 > 0)
	{
		str[size] = '\0';
		size--;
	}
	return (str);
}
