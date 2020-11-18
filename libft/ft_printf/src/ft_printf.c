/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:56:44 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:56:46 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strlenn(char *s, int c)
{
	size_t		i;

	i = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (i);
		i++;
		s++;
	}
	if (*s == (unsigned char)c)
		return (i);
	return (-1);
}

char			*ft_bpercent(char *src, size_t *n)
{
	size_t	i;
	char	*s;

	i = 0;
	if ((s = ft_strchr(src, '%')))
	{
		i = ft_strlenn(src, '%');
		write(1, src, i);
		*n += i;
		return (s);
	}
	else
	{
		i = ft_strlen(src);
		write(1, src, i);
		*n += i;
		return (NULL);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	char		*src;
	size_t		n;
	t_frmt_spec	*frmt;

	va_start(arg, format);
	n = 0;
	src = (char *)format;
	if (!(frmt = ft_new_frmt_spec()))
	{
		va_end(arg);
		return (0);
	}
	while ((src = ft_bpercent(src, &n)))
	{
		if (*(src++) == '%' && *src)
			src = ft_specifier(src, arg, frmt, &n);
		if (frmt->error)
			break ;
	}
	free(frmt);
	va_end(arg);
	return (n);
}
