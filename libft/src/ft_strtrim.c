/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:24:12 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/27 22:24:14 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_notspace(size_t i, const char *s)
{
	while (s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_space(size_t i, char const *s)
{
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static char		*ft_trim(size_t start, size_t end, const char *s)
{
	char	*str;
	size_t	i;

	if (!(str = (char*)malloc(sizeof(*str) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	size_t		i;

	if (!s)
		return (NULL);
	i = ft_space(0, s);
	if (!s[i])
		return (ft_strnew(0));
	start = i;
	while (s[i] != '\0')
	{
		i = ft_notspace(i, s);
		end = i - 1;
		i = ft_space(i, s);
	}
	return (ft_trim(start, end, s));
}
