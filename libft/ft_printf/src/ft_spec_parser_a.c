/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_parser_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:57:21 by gsinged           #+#    #+#             */
/*   Updated: 2020/08/27 15:57:25 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_spec_exclusion(t_frmt_spec *f)
{
	if (f->plus == 1)
		f->space = 0;
	if (f->left == 1)
		f->zero = 0;
	if (f->prec == 1 && ft_strchr("diouxX", f->spec) && f->precision >= 0)
		f->zero = 0;
	if (f->width < 0)
	{
		f->left = 1;
		f->width *= -1;
	}
	if (f->prec == 1 && f->precision < 0)
		f->prec = 0;
	if (f->type == 1 && f->length == 0)
		f->length = 4;
	if (f->plus || f->space)
		f->sign = 1;
	if (ft_strchr("ouxX", f->spec))
		f->sign = 0;
}
