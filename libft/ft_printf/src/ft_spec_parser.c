/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:57:07 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:57:09 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_flag_pars(char *s, t_frmt_spec *f)
{
	while (1)
	{
		if (*s == '-')
			f->left = 1;
		else if (*s == '+')
			f->plus = 1;
		else if (*s == ' ')
			f->space = 1;
		else if (*s == '#')
			f->sharp = 1;
		else if (*s == '0')
			f->zero = 1;
		else
			break ;
		s++;
	}
	return (s);
}

static char		*ft_width_precision_pars(char *s, t_frmt_spec *f, va_list arg)
{
	int		w;

	if (*s == '*' && s++)
		f->width = va_arg(arg, int);
	else if ((w = ft_atoi(s)))
	{
		f->width = w;
		while (ft_isdigit(*s))
			s++;
	}
	if (*s == '.' && s++)
	{
		f->prec = 1;
		f->precision = 0;
		if (*s == '*' && s++)
			f->precision = va_arg(arg, int);
		else if (ft_isdigit(*s) && (f->precision = ft_atoi(s)))
			while (ft_isdigit(*s))
				s++;
	}
	return (s);
}

static char		*ft_length_pars(char *s, t_frmt_spec *f)
{
	if (*s == 'h' && *(s + 1) == 'h' && s++ && s++)
		f->length = sizeof(char);
	else if (*s == 'h' && s++)
		f->length = sizeof(short);
	else if (*s == 'l' && *(s + 1) != 'l' && s++)
		f->length = sizeof(long int);
	else if (*s == 'l' && *(s + 1) == 'l' && s++ && s++)
		f->length = sizeof(long long int);
	else if (*s == 'L' && s++)
		f->length = sizeof(long double);
	return (s);
}

static int		ft_type_pars(char *s, t_frmt_spec *f)
{
	if (ft_strchr("diouxX", *s))
		f->type = 1;
	else if (ft_strchr("fFeEgG", *s))
		f->type = 2;
	else if (*s == 'c')
		f->type = 3;
	else if (*s == 's')
		f->type = 4;
	else if (*s == 'p')
		f->type = 5;
	else if (*s == '%')
		f->type = 6;
	if (f->type > 0 && f->type <= 5)
	{
		f->spec = *(s++);
		if (ft_strchr("FeEgG", f->spec))
			f->type = -1;
		else
			ft_spec_exclusion(f);
	}
	return (f->type);
}

char			*ft_spec_parser(char *s, t_frmt_spec *f, va_list arg)
{
	char	*c_bad;

	c_bad = s;
	while (!(ft_type_pars(s, f)))
	{
		s = ft_flag_pars(s, f);
		s = ft_width_precision_pars(s, f, arg);
		s = ft_length_pars(s, f);
		if (c_bad == s)
			return (s);
		else
			c_bad = s;
	}
	if (f->type == -1)
		return (s);
	return (++s);
}
