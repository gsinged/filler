/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 23:13:02 by gsinged           #+#    #+#             */
/*   Updated: 2019/11/26 23:13:04 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*res;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	res = ft_strncpy(res, s1, len);
	res[len] = '\0';
	return (res);
}
