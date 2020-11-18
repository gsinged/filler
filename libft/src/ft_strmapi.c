/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:57:07 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/27 20:57:08 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	ln;
	char			*str;

	if (!s || !f)
		return (NULL);
	ln = ft_strlen(s);
	str = (char*)malloc(sizeof(*str) * (ln + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ln)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
