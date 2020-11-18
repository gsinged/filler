/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tp1_assist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:58:15 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:58:17 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_take_number(t_frmt_spec *f, va_list arg, char *llu)
{
	*llu = 0;
	if (f->length == 1 && (f->spec == 'd' || f->spec == 'i'))
		return ((char)va_arg(arg, int));
	else if (f->length == 1)
		return ((unsigned char)va_arg(arg, int));
	if (f->length == 2 && (f->spec == 'd' || f->spec == 'i'))
		return ((short int)va_arg(arg, int));
	else if (f->length == 2)
		return ((unsigned short int)va_arg(arg, int));
	if (f->length == 4 && (f->spec == 'd' || f->spec == 'i'))
		return (va_arg(arg, int));
	else if (f->length == 4)
		return (va_arg(arg, unsigned int));
	if (f->length == 8 && (f->spec == 'd' || f->spec == 'i'))
		return (va_arg(arg, long long int));
	else if (f->length == 8)
	{
		*llu = 1;
		return (va_arg(arg, unsigned long long int));
	}
	return (0);
}

unsigned long long		ft_take_llu_sign(t_frmt_spec *f, va_list arg, \
																char *sign)
{
	long long			n;
	unsigned long long	un;
	char				llu;

	*sign = 0;
	n = ft_take_number(f, arg, &llu);
	if (n < 0 && llu != 1)
	{
		un = n * -1;
		*sign = '-';
		f->sign = 1;
	}
	else
		un = n;
	return (un);
}

int						ft_length_llu(unsigned long long n, int base)
{
	int				len;

	len = 0;
	if (n == 0)
		return (++len);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
