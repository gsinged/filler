/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:23:56 by gsinged           #+#    #+#             */
/*   Updated: 2019/09/25 17:23:57 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ln;
	size_t	i;

	if (needle[0] == '\0')
		return ((char*)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	ln = ft_strlen(needle);
	while ((ft_strncmp(haystack + i, needle, ln)) != 0 && i < len - ln + 1 &&
				haystack[i] != '\0')
		i++;
	if (i == len - ln + 1 || ln > len || haystack[i] == '\0')
		return (NULL);
	return ((char*)haystack + i);
}
