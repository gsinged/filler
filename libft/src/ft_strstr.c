/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:03:00 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/25 16:03:01 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		ln;
	int		i;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	ln = ft_strlen(needle);
	while ((ft_strncmp(haystack + i, needle, ln)) != 0 && haystack[i] != '\0')
		i++;
	if (haystack[i] == '\0')
		return (NULL);
	return ((char*)haystack + i);
}
