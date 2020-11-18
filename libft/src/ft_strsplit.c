/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 01:50:01 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/28 01:50:03 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_star(int i, char const *s, char c)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_nostar(int i, char const *s, char c)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_newst(int i, char const *s, char c)
{
	int		j;
	int		ln;

	ln = 0;
	j = 0;
	while (s[i + j] != c && s[i + j] != '\0')
	{
		ln++;
		j++;
	}
	return (ft_strsub(s, (unsigned int)i, (size_t)ln));
}

static char	**ft_fill(char const *s, char c, int ln)
{
	int		i;
	int		j;
	char	**arr;

	if (!(arr = (char**)malloc(sizeof(char*) * (ln + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < ln && s[i] != '\0')
	{
		i = ft_star(i, s, c);
		arr[j] = ft_newst(i, s, c);
		if (!s[j])
		{
			ft_strarrdel(j, &arr);
			return (NULL);
		}
		i = ft_nostar(i, s, c);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		ln;
	int		i;

	if (!s)
		return (NULL);
	ln = 0;
	i = ft_star(0, s, c);
	while (s[i] != '\0')
	{
		ln++;
		i = ft_nostar(i, s, c);
		i = ft_star(i, s, c);
	}
	return (ft_fill(s, c, ln));
}
