/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 03:53:37 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/24 03:53:39 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	len = ft_strlen(s1);
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strcpy(res, s1);
	return (res);
}
