/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:57:11 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/27 19:57:14 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	ln;
	char	*str;

	if (!s || !f)
		return (NULL);
	ln = ft_strlen(s);
	str = (char*)malloc(sizeof(*str) * (ln + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ln)
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
